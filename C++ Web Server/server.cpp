
#include "server.hpp"
#include "http/connection.hpp"
#include "settings/settingsException.hpp"

Server::Server(Settings set):
    acceptor{io_service, tcp::endpoint(tcp::v4(), set.getPort())},
    settings{set}
{
    try {
        settings.readFromFile();
    } catch (SettingsException& ex) {
        std::cout << "ERROR: " <<  ex.what() << std::endl;
        std::exit(1);
    }
}

void Server::listen() {

    std::cout << "Listening on port " << settings.getPort() << std::endl
        << "Serving directory " << settings.getDirectory() << std::endl;

    while(true) {
        tcp::socket socket(io_service);
        acceptor.accept(socket);

        Connection connection{socket};
        connection.process();
    }
}
