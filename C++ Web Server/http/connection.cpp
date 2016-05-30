
#include "connection.hpp"

#include "request/method.hpp"
#include "response/response.hpp"
#include "response/statusCode.hpp"
#include "response/contentType.hpp"

Connection::Connection(tcp::socket& sock) :
    socket{std::move(sock)}
{

}

void Connection::process() {

    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\r\n\r\n");

    std::istream is(&buffer);
    Request request = parseRequest(is);

    auto content_p = std::unique_ptr<std::string>(new std::string("<!DOCTYPE HTML><html><head><title>Title</title></head><body><p>TEST</p></body></html>"));
    Response response(StatusCode::OK);
    response.setContent(std::move(content_p), ContentType::HTML);
    std::string responseText = response.write();

    boost::system::error_code ignored_error;
    boost::asio::write(socket, boost::asio::buffer(responseText), ignored_error);
}

Request Connection::parseRequest(std::istream& requestStream) {

    // read request data
    std::string method;
    requestStream >> method;

    std::string url;
    requestStream >> url;

    Request request = Request{MethodUtils::parseMethod(method), url};

    // ignore rest of the line first line
    requestStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // all following lines contain headers
    while(!requestStream.eof()) {
        std::string header;
        std::getline(requestStream, header);

        std::size_t colonIndex = header.find(':');
        if (colonIndex != std::string::npos) {
            std::string name = header.substr(0, colonIndex);
            std::string value = header.substr(colonIndex + 1, header.size());
            request.addHeader(name, value);
        }
    }

    return request;

}
