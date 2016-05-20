
#include "contentType.hpp"

std::map<ContentType, std::string> ContentTypeMap::CONTENT_TYPE_MAP =
    {{ContentType::HTML, "text/html; charset=utf-8"}};

std::string ContentTypeMap::getDescription(ContentType contentType) {

    return CONTENT_TYPE_MAP[contentType];
}
