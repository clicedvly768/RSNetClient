#include "peer_manager.h"

namespace rsnet::core {

    void PeerManager::addPeer(const std::string& address) {
        knownPeers_.insert(address);
    }

    std::vector<PeerId> PeerManager::getActivePeers() const {
        return std::vector<PeerId>(knownPeers_.begin(), knownPeers_.end());
    }
}