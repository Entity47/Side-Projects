
#include <iostream>

#include "server.hpp"

Server::Server():
    acceptor(io_service, tcp::endpoint(tcp::v4(), 5000))
{

}

void Server::listen() {

    std::cout << "Listening on port 5000..." << std::endl;

    while(true) {
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        std::string response = responseService.buildResponse();

        boost::system::error_code ignored_error;
        boost::asio::write(socket, boost::asio::buffer(response), ignored_error);
    }
}
