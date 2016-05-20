
#include "statusCode.hpp"

std::map<StatusCode, std::string> StatusCodeMap::STATUS_CODE_MAP =
    {{StatusCode::OK, "200 OK"}};

std::string StatusCodeMap::getDescription(StatusCode statusCode) {
    return "test";
};
