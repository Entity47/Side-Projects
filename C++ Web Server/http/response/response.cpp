
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

std::string Response::write() {

    std::string message{"HTTP/1.1 " + StatusCodeMap::getDescription(statusCode) + "\r\n"};
    message += headers.write();
    message += "\r\n";

    if (content != nullptr) {
        message += *content;
    }

    return message;
}
