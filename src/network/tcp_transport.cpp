#include "tcp_transport.h"
#include <iostream>
#include <string>

// Магия для Windows и Linux в одном файле
#ifdef _WIN32
    #include <winsock2.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <unistd.h>
#endif

namespace rsnet::network {

    TcpTransport::TcpTransport(int port) : port_(port) {
#ifdef _WIN32
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            std::cerr << "[System] WSAStartup failed.\n";
        }
#endif
    }

    TcpTransport::~TcpTransport() {
        stop();
#ifdef _WIN32
        WSACleanup();
#endif
    }

    bool TcpTransport::start() {
        std::cout << "[Network] TCP Listener started on port " << port_ << std::endl;
        running_ = true;
        return true;
    }

    void TcpTransport::stop() {
        running_ = false;
        std::cout << "[Network] TCP Listener stopped." << std::endl;
    }

    bool TcpTransport::send(const PeerId& target, const DataBuffer& data) {
        if (!running_) return false;
        std::string msg(data.begin(), data.end());
        std::cout << "[Network] >>> Sending to " << target << ": \"" << msg << "\"" << std::endl;
        return true;
    }

    void TcpTransport::setOnReceive(OnReceiveCallback cb) {
        callback_ = cb;
    }
}