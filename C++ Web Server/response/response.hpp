
#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

class Response {

private:
    std::string content;

public:
    Response(std::string content);
    std::string getContent();

};

#endif
