#pragma once
#include <QtCore/QObject>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>

#include <iostream>
#include <memory>
class WSServerManager :
    public QObject
{
    Q_OBJECT
    typedef std::shared_ptr<QWebSocketServer> QWebSocketServerPtr;
    typedef std::shared_ptr<QWebSocket> QWebSocketPtr;
    QWebSocketServerPtr _websocketServer;
    QList<QWebSocketPtr> _clients;
public:
    WSServerManager(uint16_t port = 10086);
    ~WSServerManager();

signals:
    void closed();

    private slots:
    void onNewConnection();
    void processTextMessage(const QString& message);
    void socketDisconnected();
};


