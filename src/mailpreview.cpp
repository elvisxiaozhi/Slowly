#include "mailpreview.h"
#include "ui_mailpreview.h"
#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

MailPreview::MailPreview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MailPreview)
{
    ui->setupUi(this);

    setMinimumSize(850, 50);

    setWindowStyleSheet();

    ui->fromLbl->setText(tr("Theo"));
    ui->previewLbl->setText(tr("Mail Preview"));
    ui->dateLbl->setText(tr("Jul 25"));
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

bool MailPreview::event(QEvent *event)
{
    if(event->type() == QEvent::Enter) {
//        setStyleSheet("MailPreview { background: #c6e2ff; border-bottom: 1px solid #D3D3D3; }");
    }
    if(event->type() == QEvent::Leave) {
//        setStyleSheet("MailPreview { background: #c6e2ff; border-bottom: 1px solid red; }");
    }
    return QWidget::event(event);
}

void MailPreview::setWindowStyleSheet()
{
    setStyleSheet("MailPreview { background: #c6e2ff; border-bottom: 1px solid red; }"
                  "QCheckBox::indicator { border: 2px solid #cccccc; border-radius: 5px; width: 18px; height: 18px; }"
                  "QCheckBox::indicator:hover { border: 2px solid #333333; }"
                  "QCheckBox::indicator:checked { image: url(:/icons/checked.png); border: 2px solid #333333; }"
                  );
}
