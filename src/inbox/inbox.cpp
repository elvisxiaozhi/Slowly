#include "inbox.h"
#include "ui_inbox.h"

int Inbox::inboxNum = 0;

Inbox::Inbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inbox)
{
    ui->setupUi(this);

    inboxNum = 2;

    createMail();
}

Inbox::~Inbox()
{
    delete ui;
}

void Inbox::createMail()
{
    QSpacerItem *spacerItem = new QSpacerItem(1, 50, QSizePolicy::Fixed, QSizePolicy::Fixed);
    ui->vLayout->addSpacerItem(spacerItem);

    mailVec.clear();
    for(int i = 0; i < inboxNum; ++i) {
        MailPreview *mail = new MailPreview(this);
        mailVec.push_back(mail);

        ui->vLayout->addWidget(mail);
    }
    ui->vLayout->addStretch();
}
