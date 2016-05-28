
#include <string>
#include <iostream>
#include <memory>

#include "server.hpp"
#include "http/response/response.hpp"
#include "http/response/statusCode.hpp"
#include "http/response/contentType.hpp"

Server::Server():
    acceptor(io_service, tcp::endpoint(tcp::v4(), 5000))
{

}

void Server::listen() {

    std::cout << "Listening on port 5000..." << std::endl;

    while(true) {
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        boost::system::error_code ignored_error;
        boost::asio::streambuf buffer;

        std::cout << "Received request: " << std::endl;
        std::size_t n = boost::asio::read_until(socket, buffer, "\r\n\r\n");

        auto bufs = buffer.data();
        std::string data(
            boost::asio::buffers_begin(bufs),
            boost::asio::buffers_begin(bufs) + n);

        std::cout << data << std::endl;

        auto content_p = std::unique_ptr<std::string>(new std::string("<!DOCTYPE HTML><html><head><title>Title</title></head><body><p>TEST</p></body></html>"));
        Response response(StatusCode::OK);
        response.setContent(std::move(content_p), ContentType::HTML);
        std::string responseText = response.write();

        boost::asio::write(socket, boost::asio::buffer(responseText), ignored_error);
    }
}
