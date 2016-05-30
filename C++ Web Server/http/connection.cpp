
#include <iostream>

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

    Request request = readRequest();

    auto content_p = std::unique_ptr<std::string>(new std::string("<!DOCTYPE HTML><html><head><title>Title</title></head><body><p>TEST</p></body></html>"));
    Response response(StatusCode::OK);
    response.setContent(std::move(content_p), ContentType::HTML);

    writeResponse(response);
}

Request Connection::readRequest() {

    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\r\n\r\n");
    std::istream is{&buffer};

    return Request{is};
}

void Connection::writeResponse(const Response& response) {

    boost::asio::streambuf buffer;
    std::ostream output{&buffer};
    response.write(output);

    boost::system::error_code ignored_error;
    boost::asio::write(socket, buffer, ignored_error);
}
