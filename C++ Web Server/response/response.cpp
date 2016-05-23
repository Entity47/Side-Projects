
#include "response.hpp"

Response::Response(StatusCode status) :
    metadata{Metadata(status)},
    content{nullptr} {
}

void Response::setContent(std::unique_ptr<std::string> inContent, ContentType type) {
    if (inContent != nullptr) {
        metadata.addHeader("Content-Type", ContentTypeMap::getDescription(type));

        content = std::move(inContent);
        auto contentLength = content->size();
        metadata.addHeader("Content-Length", std::to_string(contentLength));
    }
}

std::string Response::write() {
    std::string message{metadata.write()};
    message += "\r\n";

    if (content != nullptr) {
        message += *content;
    }

    return message;
}
