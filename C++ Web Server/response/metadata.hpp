
#ifndef METADATA_H
#define METADATA_H

#include <string>

#include "statusCode.hpp"
#include "contentType.hpp"

class Metadata {

private:
    StatusCode statusCode;
    ContentType contentType;

public:
    Metadata(StatusCode code, ContentType contentType);
    std::string write();

};

#endif
