
#include <limits>

#include "request.hpp"

Request::Request(std::istream& requestStream)
{
    std::string methodString;
    requestStream >> methodString;
    method = MethodUtils::parseMethod(methodString);

    requestStream >> resource;
    requestStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // all following lines contain headers
    while(!requestStream.eof()) {
        std::string header;
        std::getline(requestStream, header);

        std::size_t colonIndex = header.find(':');
        if (colonIndex != std::string::npos) {
            std::string name = header.substr(0, colonIndex);
            std::string value = header.substr(colonIndex + 1, header.size());
            headers.add(name, value);
        }
    }
}

std::string Request::toString() {
    std::string requestStr{"[Method=" + MethodUtils::toString(method)};
    requestStr += ", Resource=" + resource;
    requestStr += ", Headers=" + headers.toString();
    requestStr += "]";

    return requestStr;
}
