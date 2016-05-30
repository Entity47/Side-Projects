
#include <sstream>

#include "response.hpp"

Response::Response(StatusCode status) :
    statusCode{status},
    headers{},
    content{nullptr} {
}

void Response::setContent(std::unique_ptr<std::string> inContent, ContentType type) {
    if (inContent != nullptr) {
        headers.add("Content-Type", ContentTypeMap::getDescription(type));

        content = std::move(inContent);
        auto contentLength = content->size();
        headers.add("Content-Length", std::to_string(contentLength));
    }
}

void Response::write(std::ostream& output) const {

    std::string message{"HTTP/1.1 " + StatusCodeMap::getDescription(statusCode) + "\r\n"};

    for (auto header_entry : headers) {
        message += header_entry.first + ": " + header_entry.second + "\r\n";
    }

    message += "\r\n";

    if (content != nullptr) {
        message += *content;
    }

    output << message;
}
