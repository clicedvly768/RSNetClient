#pragma once
#include "transport.h"

namespace rsnet::network {

    class TcpTransport : public ITransport {
    public:
        explicit TcpTransport(int port);
        ~TcpTransport() override;

        bool start() override;
        void stop() override;
        bool send(const PeerId& target, const DataBuffer& data) override;
        void setOnReceive(OnReceiveCallback cb) override;

    private:
        int port_;
        bool running_ = false;
        OnReceiveCallback callback_;
    };
}