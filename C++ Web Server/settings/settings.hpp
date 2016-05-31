
#ifndef SETTINGS_H
#define SETTINGS_H

class Settings {

private:
    int port;
    std::string rootDirectory;

    void setProperty(std::string name, std::string value);
    void validate();

public:
    Settings();
    void readFromFile();
    int getPort();
    std::string getDirectory();

};

#endif
