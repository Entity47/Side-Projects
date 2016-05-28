
#ifndef REQUEST_H
#define REQUEST_H

#include <string>

#include "../headers.hpp"
#include "method.hpp"

class Request {

private:
    Method method;
    std::string resource;
    std::string httpVersion;
    Headers headers;

public:
    void setMethod(Method m);
    void addheader(std::string name, std::string value);
};

#endif
