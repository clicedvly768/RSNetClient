#pragma once
#include <memory>
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

    private:
        void onMessageReceived(const PeerId& sender, const DataBuffer& data);

        std::unique_ptr<network::ITransport> transport_;
        std::unique_ptr<PeerManager> peerManager_;
        bool isRunning_;
    };
}