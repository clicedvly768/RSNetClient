#include "core/node.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

void printHelp() {
    std::cout << "\n--- RSNet Client CLI ---\n"
              << "  connect <ip:port>  : Add a peer\n"
              << "  send <msg>         : Send message to all peers\n"
              << "  exit               : Quit\n"
              << "------------------------\n";
}

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    rsnet::core::Node node;

    try {
        node.init();
        node.start();
    } catch (const std::exception& e) {
        std::cerr << "Critical error: " << e.what() << std::endl;
        return -1;
    }

    printHelp();

    std::string command;
    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "connect") {
            std::string addr;
            std::cin >> addr;
            node.connectToPeer(addr);
        }
        else if (command == "send") {
            std::string msg;
            std::getline(std::cin, msg);

            if (!msg.empty() && msg[0] == ' ') msg.erase(0, 1);

            if (!msg.empty()) {
                node.broadcastMessage(msg);
            }
        }
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }

    node.shutdown();
    return 0;
}