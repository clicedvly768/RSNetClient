#pragma once
#include <QObject>
#include <QString>
#include "core/node.h"

class NodeBridge : public QObject {
    Q_OBJECT
public:
    explicit NodeBridge(QObject *parent = nullptr) : QObject(parent) {
        node_.setLogCallback([this](const std::string& msg) {
            emit logMessage(QString::fromStdString(msg));
        });

        node_.init();
    }

    void startNode() {
        node_.start();
    }

public slots:
    void connectTo(const QString &ip) {
        node_.connectToPeer(ip.toStdString());
    }

    void sendBroadcast(const QString &msg) {
        node_.broadcastMessage(msg.toStdString());
    }

    signals:
        void logMessage(const QString &text);

private:
    rsnet::core::Node node_;
};