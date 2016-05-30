
#include "server.hpp"
#include "http/connection.hpp"

Server::Server(int port):
    acceptor(io_service, tcp::endpoint(tcp::v4(), port))
{

}

void Server::listen() {

    std::cout << "Listening on port 5000..." << std::endl;

    while(true) {
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        Connection connection{socket};
        connection.process();
    }
}
