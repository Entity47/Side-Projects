
#include <iostream>
#include <memory>

#include "server.hpp"
#include "response/response.hpp"
#include "response/statusCode.hpp"
#include "response/contentType.hpp"

Server::Server():
    acceptor(io_service, tcp::endpoint(tcp::v4(), 5000))
{

}

void Server::listen() {

    std::cout << "Listening on port 5000..." << std::endl;

    while(true) {
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        auto content_p = std::unique_ptr<std::string>(new std::string("<!DOCTYPE HTML><html><head><title>Title</title></head><body><p>TEST</p></body></html>"));
        Response response(StatusCode::OK);
        response.setContent(std::move(content_p), ContentType::HTML);
        std::string responseText = response.write();

        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(responseText), ignored_error);
    }
}
