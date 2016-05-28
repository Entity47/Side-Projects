
#include "request.hpp"

void Request::setMethod(Method m) {
    method = m;
}

void Request::addheader(std::string name, std::string value) {
    headers.add(name, value);
}
