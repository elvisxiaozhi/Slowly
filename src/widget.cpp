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
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint); //hide original title bar

    titlebar = new TitleBar(this);

    ui->contVLayout->addWidget(titlebar);
    ui->contVLayout->addStretch();

    connect(titlebar, &TitleBar::actionChanged, this, &Widget::titlebarActChanged);
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
