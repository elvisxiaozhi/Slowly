#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(1250, 800);

    createSidebar();
    createTitlebar();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createSidebar()
{
    sidebar = new Sidebar(this);

    ui->sidebarVLayout->addWidget(sidebar);
}

void Widget::createTitlebar()
{
    titlebar = new TitleBar(this);

    ui->contVLayout->addWidget(titlebar);
    ui->contVLayout->addStretch();
}
