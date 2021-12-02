#include "WSServerManager.h"
#include <QtCore/QDebug>


WSServerManager::WSServerManager(uint16_t port)
  :_websocketServer(new QWebSocketServer(QStringLiteral("MyServer"), QWebSocketServer::NonSecureMode))
{
    if (this->_websocketServer->listen(QHostAddress::Any, port))
    {
        QObject::connect(_websocketServer.get(), SIGNAL(newConnection()), this, SLOT(onNewConnection()));
        qInfo() << QString("WSServerManager listen %1 success.").arg(port);
    }
    else
    {
        qInfo() << QString("WSServerManager listen %1 failed.").arg(port);
    }
}


WSServerManager::~WSServerManager()
{
}

void WSServerManager::onNewConnection()
{
    qInfo() << "WSServerManager::onNewConnection";
    QWebSocketPtr socket(this->_websocketServer->nextPendingConnection());

    QObject::connect(socket.get(), SIGNAL(textMessageReceived(const QString&)), this, SLOT(processTextMessage(const QString&)));
    QObject::connect(socket.get(), SIGNAL(disconnected()), this, SLOT(socketDisconnected()));

    this->_clients.append(socket);
}

void WSServerManager::processTextMessage(const QString& message)
{
    qInfo() << "WSServerManager::processTextMessage: " << message;
}

void WSServerManager::socketDisconnected()
{
    qInfo() << "WSServerManager::socketDisconnected";
}