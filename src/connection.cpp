#include "connection.h"
#include <QDebug>
#include <QHostAddress>

Connection::Connection(QWidget *parent) : QWidget(parent)
{
    tcpSocket = new QTcpSocket(this);
}

void Connection::connect()
{
    tcpSocket->abort();
    tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 6666);
    if(tcpSocket->waitForConnected()) {
        emit connected(true);
    }
    else {
        emit connected(false);
    }
}
