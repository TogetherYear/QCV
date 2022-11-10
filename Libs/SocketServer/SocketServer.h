#pragma once

#include <QObject>
#include <QDebug>
#include <QtWebSockets>
#include <QJsonObject>
#include <QJsonDocument>
#include "Templates/Singleton.hpp"

class SocketServer : public QObject,public Singleton<SocketServer>
{
    Q_OBJECT
public:
    explicit SocketServer(QObject *parent = nullptr);
    virtual ~SocketServer();

signals:
    void OnNewConnection();
    void OnMessage(const QJsonObject& msg);
    void OnDisconnected();
    void OnClose();
    void OnResetSocket();

public:
    void Run();

private:
    void CreateReception();
    void CreateFeedback();

private:
    QJsonObject reception;
    QJsonObject feedback;

private:
    void CreateSocketServer();
    void NewConnection();
    void Message(const QString& msg);
    void Disconnected();
    void Close();
    void ResetSocket();

private:
    QWebSocketServer* server;
    QWebSocket* currentSocket;
    quint32 port = 6768;
    bool isConnect = false;

};

