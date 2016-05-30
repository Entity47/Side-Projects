
#include "headers.hpp"

void Headers::add(std::string header, std::string headerValue) {
    // allow overriding of headers
    headers[header] = headerValue;
}

std::map<std::string, std::string>::const_iterator Headers::begin() const {
    return headers.cbegin();
}

std::map<std::string, std::string>::const_iterator Headers::end() const {
    return headers.cend();
}

std::string Headers::toString() {
    std::string headersStr{"["};
    for (auto header_entry : headers) {
        headersStr += header_entry.first + ":" + header_entry.second + " ";
    }
    headersStr += "]";

    return headersStr;
}
