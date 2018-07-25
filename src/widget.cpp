#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(1250, 800);

    connection = new Connection(this);

    createSidebar();
    createTitlebar();
    createConts();

    ui->contVLayout->addStretch();

    connect(connection, &Connection::connected, [this](bool connected){ titlebar->isOnline = connected; });
    connection->connect();
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
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint); //hide original title bar

    titlebar = new TitleBar(this);

    ui->contVLayout->addWidget(titlebar);

    connect(titlebar, &TitleBar::actionChanged, this, &Widget::titlebarActChanged);
}

void Widget::createConts()
{
    inbox = new Inbox(this);

    ui->contVLayout->addWidget(inbox);
}

void Widget::titlebarActChanged(int index)
{
    if(index == 1) {
        this->showMinimized();
    }
    if(index == 2) {
        this->close();
    }
}
