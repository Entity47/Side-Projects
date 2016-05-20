
#include "metadata.hpp"

Metadata::Metadata(StatusCode status, ContentType contentType) :
    statusCode{status}, contentType{contentType} {
}

std::string Metadata::write() {

    std::string message{"HTTP/1.1 " + StatusCodeMap::getDescription(statusCode) + "\r\n"};
    message += "Content-Type: " + ContentTypeMap::getDescription(contentType) + "\r\n";

    return message;
}
