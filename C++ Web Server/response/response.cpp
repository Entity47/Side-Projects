
#include "response.hpp"

Response::Response(std::string content) : content{content} {

}

std::string Response::getContent() {
    return content;
}
