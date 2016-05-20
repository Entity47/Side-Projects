
#import "response.hpp"

Response::Response(StatusCode status, ContentType type, std::string content) :
    metadata{Metadata(status, type)}, content{content} {

}

std::string Response::write() {
    std::string message{metadata.write()};
    message += "\r\n";
    message += content;

    return message;
}
