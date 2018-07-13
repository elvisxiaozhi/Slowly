#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1250, 800);

    createSidebar();
    createContWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSidebar()
{
    sidebar = new Sidebar(this);
    addDockWidget(Qt::LeftDockWidgetArea, sidebar);
}

void MainWindow::createContWindow()
{
    setCentralWidget(ui->widget);

    titleBar = new TitleBar(this);

    ui->vLayout->addWidget(titleBar);
    ui->vLayout->addStretch();
}
