#ifndef INBOX_H
#define INBOX_H

#include <QWidget>
#include "mailpreview.h"

namespace Ui {
class Inbox;
}

class Inbox : public QWidget
{
    Q_OBJECT

public:
    explicit Inbox(QWidget *parent = 0);
    ~Inbox();

    static int inboxNum;

private:
    Ui::Inbox *ui;

    QVector<MailPreview *> mailVec;

    void createMail();
};

#endif // INBOX_H
