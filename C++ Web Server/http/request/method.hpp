
#ifndef METHOD_H
#define METHOD_H

#include <string>

enum class Method {
    GET,
    PUT,
    POST,
    DELETE
};

class MethodUtils {

public:
    static Method parseMethod(std::string method);
    static std::string toString(Method method);

};

#endif
