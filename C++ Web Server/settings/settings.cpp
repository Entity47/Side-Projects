
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include "settings.hpp"
#include "settingsException.hpp"

Settings::Settings() :
    port{5000},
    rootDirectory{""}
{

}

void Settings::readFromFile() {
    std::ifstream fileStream;
    fileStream.open("config.yml", std::ifstream::in);
    if (!fileStream.is_open()) {
        std::string message{"Unable to read config.yml. File not found."};
        throw SettingsException(message);
    }

    while (!fileStream.eof()) {
        std::string input;
        std::getline(fileStream, input);

        std::size_t separatorIndex = input.find(":");
        if (separatorIndex != std::string::npos) {
            std::string name = input.substr(0, separatorIndex);
            boost::trim(name);
            std::string value = input.substr(separatorIndex+1, input.size());
            boost::trim(value);
            
            setProperty(name, value);
        }
    }

    validate();
}

void Settings::setProperty(std::string name, std::string value) {
    if (name == "port") {
        port = std::stoi(value);
    } else if (name == "directory") {
        rootDirectory = value;
    } else {
        std::cout << "Unknown setting [" << name << "]" << std::endl;
    }
}

void Settings::validate() {
    if (rootDirectory.empty()) {
        throw SettingsException("No directory defined");
    }
}

int Settings::getPort() {
    return port;
}

std::string Settings::getDirectory() {
    return rootDirectory;
}
