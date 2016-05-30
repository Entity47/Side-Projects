
#ifndef CONNECTION_H
#define CONNECTION_H

#include <boost/asio.hpp>

#include "request/request.hpp"

using boost::asio::ip::tcp;

class Connection {

private:
    tcp::socket socket;
    Request parseRequest(std::istream& requestStream);

public:
    Connection(tcp::socket& sock);
    void process();
};

#endif
