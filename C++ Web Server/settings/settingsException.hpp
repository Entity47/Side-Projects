
#ifndef SETTINGS_EXCEPTION_H
#define SETTINGS_EXCEPTION_H

#include <string>
#include <exception>

class SettingsException : public std::exception {

private:
    std::string reason;

public:
    SettingsException(std::string r) {
        reason = r;
    }

    virtual const char* what() const noexcept override {
        return reason.c_str();
    }

};

#endif
