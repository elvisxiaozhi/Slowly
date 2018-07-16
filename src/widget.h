#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "sidebar.h"
#include "titlebar.h"
#include "inbox/inbox.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    Sidebar *sidebar;
    TitleBar *titlebar;
    Inbox *inbox;

    void createSidebar();
    void createTitlebar();
    void createConts();

private slots:
    void titlebarActChanged(int);
};

#endif // WIDGET_H
