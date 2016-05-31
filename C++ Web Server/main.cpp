
#include "server.hpp"
#include "settings/settings.hpp"

int main() {

    Settings settings;
    Server server(settings);
    server.listen();
}
