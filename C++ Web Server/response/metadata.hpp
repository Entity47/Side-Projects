
#ifndef METADATA_H
#define METADATA_H

#include <string>
#include <map>

#include "statusCode.hpp"

class Metadata {

private:
    std::map<std::string, std::string> headers;
    StatusCode statusCode;

public:
    Metadata(StatusCode code);
    void addHeader(std::string header, std::string headerValue);
    std::string write();

};

#endif
