#pragma once
#include <rsnet/types.h>
#include <functional>
#include <string>

namespace rsnet::network {
    class ITransport {
    public:
        virtual ~ITransport() = default;

        virtual bool start() = 0;
        virtual void stop() = 0;
        virtual bool send(const PeerId& target, const DataBuffer& data) = 0;

        using OnReceiveCallback = std::function<void(const PeerId&, const DataBuffer&)>;
        virtual void setOnReceive(OnReceiveCallback cb) = 0;
    };
}