
#include "metadata.hpp"

Metadata::Metadata(StatusCode status) :
    statusCode{status} {

}

void Metadata::addHeader(std::string header, std::string headerValue) {
    // allow overriding of headers
    headers[header] = headerValue;
}

std::string Metadata::write() {

    std::string message{"HTTP/1.1 " + StatusCodeMap::getDescription(statusCode) + "\r\n"};

    for (auto header_entry : headers) {
        message += header_entry.first + ": " + header_entry.second + "\r\n";
    }

    return message;
}
