
#ifndef RESPONSE_H
#define RESPONSE_H

#import <string>

#import "contentType.hpp"
#import "statusCode.hpp"
#import "metadata.hpp"

class Response {

private:
    Metadata metadata;
    std::string content;

public:
    Response(StatusCode status, ContentType type, std::string content);
    std::string write();

};

#endif
