#ifndef CONNECTION_H
#define CONNECTION_H

#include <QTcpServer>

class Connection
{
public:
    Connection();

private:
    QTcpServer *tcpServer;
};

#endif // CONNECTION_H
