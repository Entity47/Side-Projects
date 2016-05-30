
#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class Server {
    boost::asio::io_service io_service;
    tcp::acceptor acceptor;

public:
    Server(int port);
    void listen();

};

#endif
