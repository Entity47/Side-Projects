
#include <iostream>
#include <limits>

#include "messageHandler.hpp"
#include "request/method.hpp"

Request MessageHandler::parseRequest(std::istream &requestStream) {

    // read request data
    std::string method;
    requestStream >> method;

    std::string url;
    requestStream >> url;

    Request request = Request{MethodUtils::parseMethod(method), url};

    // ignore rest of the line first line
    requestStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // all following lines contain headers
    while(!requestStream.eof()) {
        std::string header;
        std::getline(requestStream, header);

        std::size_t colonIndex = header.find(':');
        if (colonIndex != std::string::npos) {
            std::string name = header.substr(0, colonIndex);
            std::string value = header.substr(colonIndex + 1, header.size());
            request.addHeader(name, value);
        }
    }

    std::cout << "Received request: " << request.toString() << std::endl;

    return request;

}
