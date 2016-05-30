
#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <string>
#include <boost/asio.hpp>

#include "request/request.hpp"

class MessageHandler {

private:

public:
    Request parseRequest(std::istream &requestStream);

};

#endif
