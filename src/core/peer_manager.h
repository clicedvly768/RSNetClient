#pragma once
#include <rsnet/types.h>
#include <vector>
#include <string>
#include <unordered_set>

namespace rsnet::core {

    class PeerManager {
    public:
        void addPeer(const std::string& address);
        std::vector<PeerId> getActivePeers() const;

    private:
        std::unordered_set<PeerId> knownPeers_;
    };
}