#include "SocketServer.h"

SocketServer::SocketServer(QObject *parent) : QObject(parent)
{

}

SocketServer::~SocketServer()
{

}

void SocketServer::Run()
{
    CreateReception();
    CreateFeedback();
    CreateSocketServer();
}

void SocketServer::CreateReception()
{
    reception.insert("code",-1);
}

void SocketServer::CreateFeedback()
{
    feedback.insert("code",-1);
}

void SocketServer::CreateSocketServer()
{
    server = new QWebSocketServer("Fracture",QWebSocketServer::NonSecureMode,this);
    if(server->listen(QHostAddress::Any,port))
    {
        connect(server,&QWebSocketServer::newConnection,this,&SocketServer::NewConnection);
        connect(server,&QWebSocketServer::closed,this,&SocketServer::Close);
    }
}

void SocketServer::NewConnection()
{
    ResetSocket();
    currentSocket = server->nextPendingConnection();
    connect(currentSocket,&QWebSocket::textMessageReceived,this,&SocketServer::Message);
    connect(currentSocket,&QWebSocket::disconnected,this,&SocketServer::Disconnected);
    isConnect = true;
    emit OnNewConnection();

}

void SocketServer::Message(const QString &msg)
{
    const QJsonObject& temp = QJsonDocument::fromJson(msg.toUtf8()).object();
    qDebug()<<temp;
    emit OnMessage(temp);
}

void SocketServer::Disconnected()
{
    ResetSocket();
    emit OnDisconnected();
}

void SocketServer::Close()
{
    emit OnClose();
}

void SocketServer::ResetSocket()
{
    if(isConnect)
    {
        disconnect(currentSocket,&QWebSocket::textMessageReceived,this,&SocketServer::Message);
        disconnect(currentSocket,&QWebSocket::disconnected,this,&SocketServer::Disconnected);
        currentSocket->close();
        isConnect = false;
        qDebug()<<"ResetSocket";
        emit OnResetSocket();
    }
}












