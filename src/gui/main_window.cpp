#include "main_window.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("RSNet Client");
    resize(600, 450);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *mainLayout = new QVBoxLayout(central);

    QGroupBox *grpConnect = new QGroupBox("Connection");
    QHBoxLayout *layoutConnect = new QHBoxLayout(grpConnect);
    ipInput = new QLineEdit("127.0.0.1:8080");
    btnConnect = new QPushButton("Connect");
    layoutConnect->addWidget(new QLabel("Peer Address:"));
    layoutConnect->addWidget(ipInput);
    layoutConnect->addWidget(btnConnect);
    mainLayout->addWidget(grpConnect);

    logArea = new QTextEdit();
    logArea->setReadOnly(true);
    logArea->setStyleSheet("background-color: #2b2b2b; color: #00ff00; font-family: Consolas;");
    mainLayout->addWidget(logArea);

    QHBoxLayout *layoutSend = new QHBoxLayout();
    msgInput = new QLineEdit();
    msgInput->setPlaceholderText("Type a message...");
    btnSend = new QPushButton("Send Broadcast");
    layoutSend->addWidget(msgInput);
    layoutSend->addWidget(btnSend);
    mainLayout->addLayout(layoutSend);

    bridge = new NodeBridge(this);
    connect(bridge, &NodeBridge::logMessage, this, &MainWindow::appendLog);
    connect(btnConnect, &QPushButton::clicked, this, &MainWindow::onConnectBtn);
    connect(btnSend, &QPushButton::clicked, this, &MainWindow::onSendBtn);
    connect(msgInput, &QLineEdit::returnPressed, this, &MainWindow::onSendBtn);
    bridge->startNode();
}

void MainWindow::onConnectBtn() {
    bridge->connectTo(ipInput->text());
}

void MainWindow::onSendBtn() {
    QString txt = msgInput->text();
    if (txt.isEmpty()) return;

    bridge->sendBroadcast(txt);
    msgInput->clear();
}

void MainWindow::appendLog(const QString &text) {
    logArea->append(text);
}