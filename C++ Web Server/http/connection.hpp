
#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>

#include "request/request.hpp"
#include "response/response.hpp"

using boost::asio::ip::tcp;

class Connection {

private:
    tcp::socket socket;
    Request readRequest();
    void writeResponse(const Response& response);

public:
    Connection(tcp::socket& sock);
    void process();
};

#endif
