#include "node.h"
#include "network/tcp_transport.h"
#include <iostream>

namespace rsnet::core {

    Node::Node() : isRunning_(false) {
        peerManager_ = std::make_unique<PeerManager>();
        transport_ = std::make_unique<network::TcpTransport>(8080);
    }

    Node::~Node() {
        shutdown();
    }

    void Node::init() {
        transport_->setOnReceive([this](const PeerId& sender, const DataBuffer& data) {
            this->onMessageReceived(sender, data);
        });
    }

    void Node::start() {
        if (transport_->start()) {
            isRunning_ = true;
            std::cout << "[Node] System is ONLINE." << std::endl;
        }
    }

    void Node::shutdown() {
        if (isRunning_) {
            transport_->stop();
            isRunning_ = false;
        }
    }

    void Node::connectToPeer(const std::string& address) {
        std::cout << "[Node] Added peer: " << address << std::endl;
        peerManager_->addPeer(address);
    }

    void Node::broadcastMessage(const std::string& message) {
        auto peers = peerManager_->getActivePeers();
        if (peers.empty()) {
            std::cout << "[Node] No peers connected. Use 'connect <ip>' first." << std::endl;
            return;
        }

        DataBuffer data(message.begin(), message.end());
        for (const auto& peer : peers) {
            transport_->send(peer, data);
        }
    }

    void Node::onMessageReceived(const PeerId& sender, const DataBuffer& data) {
        std::string msg(data.begin(), data.end());
        std::cout << "[Node] Received from " << sender << ": " << msg << std::endl;
    }
}