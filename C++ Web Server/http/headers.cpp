
#include "headers.hpp"

void Headers::add(std::string header, std::string headerValue) {
    // allow overriding of headers
    headers[header] = headerValue;
}

std::string Headers::write() {
    std::string message;
    for (auto header_entry : headers) {
        message += header_entry.first + ": " + header_entry.second + "\r\n";
    }

    return message;
}

std::string Headers::toString() {
    std::string headersStr{"["};
    for (auto header_entry : headers) {
        headersStr += header_entry.first + ":" + header_entry.second + " ";
    }
    headersStr += "]";

    return headersStr;
}
