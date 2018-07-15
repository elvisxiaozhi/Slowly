#include "titlebar.h"
#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>
#include <windows.h>
#include <QWindow>

TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);

    checkedAct = NULL;
    hoveredAct = NULL;

    userName = "Theodore";

    addAction(userName, QIcon(""));
    addAction("—", QIcon(""));
    addAction("×", QIcon(""));

    setStyleSheet("QWidget { background-color: white; }");
    setFixedSize(1050, 45);
}

QAction *TitleBar::addAction(const QString &text, const QIcon &icon)
{
    QAction *action = new QAction(icon, text, this);
    action->setCheckable(true);
    actList.push_back(action);
    return action;
}

QAction *TitleBar::actionAt(const QPoint &point)
{
    int posX = 915;
    for(auto action : actList) {
        //35, 35 or whatever it fits, they have to be less than its width and height 45, 45
        //or sometimes the hover effect will stay
        QRect actRect(posX, 0, 35, 35);
        if(actRect.contains(point)) {
            return action;
        }
        posX += 45;
    }

    return NULL;
}

void TitleBar::paintEvent(QPaintEvent *event)
{
    //to make the custom widget able to set style sheet
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    QFont font("Times", 13);
    painter.setFont(font);

    int posX = 915 + 12; //move the icon to the center, so + 12

    for(auto action : actList) {
        if(action == hoveredAct) {
            painter.setPen(QColor(255,255,255)); //change text color when hover

            if(action->text() == userName) {
                painter.fillRect(QRect(960 - (userName.size() + 2) * 8, 0, (userName.size() + 2) * 8, 45), QColor(0, 255, 0));
            }
            if(action->text() == "—") {
                painter.fillRect(QRect(960, 0, 45, 45), QColor(0,255,255)); //set background color
            }
            if(action->text() == "×") {
                painter.fillRect(QRect(1005, 0, 45, 45), QColor(233, 75, 60)); //set background color
            }
        }
        else {
            painter.setPen(QColor(128,128,128)); //change the text color to normal grey when not hover
        }

        if(action->text() == userName) {
            painter.setPen(QColor(25,25,25));
            QFont userNamefont("Times", 8);
            painter.setFont(userNamefont);
            QRect textRect(960 - userName.size() * 8 - 5, 15, event->rect().width(), event->rect().height());
            painter.drawText(textRect, action->text());
        }
        else {
            painter.setFont(font);
            QRect textRect(posX, 8, event->rect().width(), event->rect().height());
            painter.drawText(textRect, action->text());
        }

        posX += 45;
    }
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons().testFlag(Qt::LeftButton)) //use the native windows api, the issue that window suddently move will not show, do not know why
    {
        HWND hWnd = ::GetAncestor((HWND)(window()->windowHandle()->winId()), GA_ROOT);
        POINT pt;
        ::GetCursorPos(&pt);
        ::ReleaseCapture();
        ::SendMessage(hWnd, WM_NCLBUTTONDOWN, HTCAPTION, POINTTOPOINTS(pt));
    }

    QAction *action = actionAt(event->pos());
    checkedAct = action;
    if(checkedAct != NULL) {
        int index = std::find(actList.begin(), actList.end(), checkedAct) - actList.begin();
        emit actionChanged(index);
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    QAction *action = actionAt(event->pos());
    hoveredAct = action;
    update(); //update must be in the last, or the window will suddently move to another place
}
