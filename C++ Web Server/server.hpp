
#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>

#include "settings/settings.hpp"

using boost::asio::ip::tcp;

class Server {
    boost::asio::io_service io_service;
    tcp::acceptor acceptor;
    Settings settings;

public:
    Server(Settings settings);
    void listen();

};

#endif
