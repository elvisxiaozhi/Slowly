#include "connection.h"

Connection::Connection()
{
    tcpServer = new QTcpServer();
    tcpServer->listen(QHostAddress::Any, 6666);
}
