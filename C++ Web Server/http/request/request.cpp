
#include "request.hpp"

Request::Request(Method m, std::string url) :
    method{m},
    resource{url}
{
    method = m;
}

void Request::addHeader(std::string name, std::string value) {
    headers.add(name, value);
}

std::string Request::toString() {
    std::string requestStr{"[Method=" + MethodUtils::toString(method)};
    requestStr += ", Resource=" + resource;
    requestStr += ", Headers=" + headers.toString();
    requestStr += "]";

    return requestStr;
}
