#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "sidebar.h"
#include "titlebar.h"

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

    void createSidebar();
    void createTitlebar();
};

#endif // WIDGET_H
