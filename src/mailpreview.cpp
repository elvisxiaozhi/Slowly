#include "mailpreview.h"
#include "ui_mailpreview.h"
#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>

MailPreview::MailPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MailPreview)
{
    ui->setupUi(this);

    setMinimumSize(850, 100);

    setStyleSheet("QWidget { background: rgb(240, 248, 255); border-bottom: 1px solid /*#D3D3D3*/red; }");
}

MailPreview::~MailPreview()
{
    delete ui;
}

void MailPreview::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
