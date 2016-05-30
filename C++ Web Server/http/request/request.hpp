
#ifndef REQUEST_H
#define REQUEST_H

#include <string>

#include "../headers.hpp"
#include "method.hpp"

class Request {

private:
    Method method;
    std::string resource;
    Headers headers;

public:
    Request(Method m, std::string resource);
    void addHeader(std::string name, std::string value);
    std::string toString();
};

#endif
