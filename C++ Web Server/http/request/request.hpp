
#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <istream>

#include "../headers.hpp"
#include "method.hpp"

class Request {

private:
    Method method;
    std::string resource;
    Headers headers;

public:
    Request(std::istream& requestStream);
    std::string toString();
};

#endif
