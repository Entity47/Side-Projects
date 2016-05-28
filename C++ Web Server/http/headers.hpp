
#ifndef HEADERS_H
#define HEADERS_H

#include <string>
#include <map>

class Headers {

private:
    std::map<std::string, std::string> headers;

public:
    void add(std::string header, std::string headerValue);
    std::string write();

};

#endif
