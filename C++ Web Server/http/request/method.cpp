
#include "method.hpp"

Method MethodUtils::parseMethod(std::string method) {
    // TODO: Add error handler for request process
    if (method == "GET") {
        return Method::GET;
    } else if (method == "PUT") {
        return Method::PUT;
    } else if (method == "DELETE") {
        return Method::DELETE;
    } else if (method == "POST") {
        return Method::POST;
    }

    // Just be lazy for now...
    return Method::GET;
}

std::string MethodUtils::toString(Method method) {
    if (method == Method::GET) {
        return "GET";
    } else if (method == Method::PUT) {
        return "PUT";
    } else if (method == Method::DELETE) {
        return "DELETE";
    } else if (method == Method::POST) {
        return "POST";
    }

    // Should never get here
    return "UNKNOWN";
}
