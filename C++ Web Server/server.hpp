
#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>

#include "response/responseService.hpp"

using boost::asio::ip::tcp;

class Server {
    boost::asio::io_service io_service;
    tcp::acceptor acceptor;

    ResponseService responseService;

public:
    Server();
    void listen();

};

#endif
