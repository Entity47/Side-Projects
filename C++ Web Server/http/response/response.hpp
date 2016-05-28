
#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <memory>

#include "contentType.hpp"
#include "statusCode.hpp"
#include "../headers.hpp"
#include "contentType.hpp"

class Response {

private:
    StatusCode statusCode;
    Headers headers;
    std::unique_ptr<std::string> content;

public:
    Response(StatusCode status);
    void setContent(std::unique_ptr<std::string> inContent, ContentType type);
    std::string write();

};

#endif