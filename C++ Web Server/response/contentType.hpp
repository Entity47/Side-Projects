
#ifndef CONTENT_TYPE_H
#define CONTENT_TYPE_H

#include <string>
#include <map>

enum class ContentType {
    HTML
};

class ContentTypeMap {

private:

    static std::map<ContentType, std::string> CONTENT_TYPE_MAP;

public:

    static std::string getDescription(ContentType contentType);

};

#endif
