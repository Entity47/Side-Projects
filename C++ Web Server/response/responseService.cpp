
#include "responseService.hpp"

std::string ResponseService::buildResponse() {
    std::string message{"HTTP/1.1 200 OK\r\n"};
    message += "Content-Type: text/html; charset=utf-8\r\n";
    message += "\r\n";
    message += "<!DOCTYPE HTML><html><head><title>Title</title></head><body><p>TEST2</p></body></html>";

    return message;
}
