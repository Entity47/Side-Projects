
#ifndef STATUSCODE_H
#define STATUSCODE_H

#include <string>
#include <map>

enum class StatusCode {
    OK
};

class StatusCodeMap {

private:
    static std::map<StatusCode, std::string> STATUS_CODE_MAP;

public:
    static std::string getDescription(StatusCode statusCode);
};

#endif
