#ifndef CONNECTION_H
#define CONNECTION_H

#include <QWidget>
#include <QTcpSocket>

class Connection : public QWidget
{
    Q_OBJECT
public:
    explicit Connection(QWidget *parent = nullptr);
    void connect();

private:
    QTcpSocket *tcpSocket;

signals:
    void connected(bool);

private slots:
};

#endif // CONNECTION_H
