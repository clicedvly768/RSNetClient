#pragma once
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include "node_bridge.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onConnectBtn();
    void onSendBtn();
    void appendLog(const QString &text);

private:
    QTextEdit *logArea;
    QLineEdit *ipInput;
    QLineEdit *msgInput;
    QPushButton *btnConnect;
    QPushButton *btnSend;

    NodeBridge *bridge;
};