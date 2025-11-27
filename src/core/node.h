#pragma once
#include <memory>
#include <functional>
#include <string>
#include "network/transport.h"
#include "peer_manager.h"

namespace rsnet::core {

    class Node {
    public:
        Node();
        ~Node();

        void init();
        void start();
        void shutdown();

        void connectToPeer(const std::string& address);
        void broadcastMessage(const std::string& message);

        using LogCallback = std::function<void(const std::string&)>;
        void setLogCallback(LogCallback cb) { logCallback_ = cb; }

    private:
        void log(const std::string& msg); // Вспомогательный метод
        void onMessageReceived(const PeerId& sender, const DataBuffer& data);

        std::unique_ptr<network::ITransport> transport_;
        std::unique_ptr<PeerManager> peerManager_;
        bool isRunning_;
        LogCallback logCallback_;
    };

}
