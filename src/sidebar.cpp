#include "sidebar.h"
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QIcon>
#include "inbox/inbox.h"

Sidebar::Sidebar(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(200, 100);

    setMouseTracking(true);

    addAction(tr("Inbox"), QIcon(":/icons/inbox.png"));
    addAction(tr("Sent"), QIcon(":/icons/sent.png"));
    addAction(tr("Drafts"), QIcon(":/icons/drafts.png"));
    addAction(tr("Penpals"), QIcon(":/icons/world.png"));
    addAction(tr("Me"), QIcon(":/icons/boy.png"));

    checkedAct = actList[0];
    hoveredAct = NULL;
}

QAction *Sidebar::addAction(const QString &text, const QIcon &icon)
{
    QAction *action = new QAction(icon, text, this);
    action->setCheckable(true);
    actList.push_back(action);
    return action;
}

QAction *Sidebar::actionAt(const QPoint &point)
{
    int posY = 110;
    for(int i = 0; i < actList.size(); ++i) {
        QRect actRect(0, posY, 195, 50); //set width to 195 and height to 50, or the hover effect will sometimes show and the checked effect will disappear
        if(actRect.contains(point)) {
            return actList[i];
        }
        posY += 50;
        if(i == 2) {
            posY += 50;
        }
    }

    return NULL;
}

void Sidebar::paintLogo(QPainter &painter)
{
    //paint the title and it has to be after menu is drew
    painter.setPen(QColor(255, 255, 255));
    painter.setFont(QFont("Futura", 20));
    painter.fillRect(QRect(0, 0, 200, 80), QColor(0, 255, 0)); //paint rect first
    painter.drawText(QRect(75, 20, 100, 50), "Slowly"); //then draw text on the rect, or text will not show

    //paint icon, icon must be piant after paint rect bg color
    QIcon icon(":/icons/snail.png");
    QRect iconRect(30, 25, 35, 35);
    icon.paint(&painter, iconRect);
}

void Sidebar::paintMenu(QPainter &painter, QPaintEvent *event)
{
    int posY = 110;
    for(int i = 0; i < actList.size(); ++i) {
        if(actList[i] == checkedAct) {
            QPen checkedPen;  // creates a default pen
            checkedPen.setWidth(5);
            checkedPen.setBrush(Qt::red);
            painter.setPen(checkedPen);
            painter.drawLine(0, posY, 0, posY + 30);

            QFont checkedFont("Times", 10, QFont::Bold);
            painter.setFont(checkedFont);
            painter.setPen(QColor(102,102,102));
        }
        else {
            if(actList[i] == hoveredAct) {
                QFont uncheckedFont("Times", 10, QFont::Bold);
                painter.setFont(uncheckedFont);

                QPen hoveredPen;
                hoveredPen.setWidth(5);
                hoveredPen.setBrush(QColor(255, 192, 203));
                painter.setPen(hoveredPen);
                painter.drawLine(0, posY, 0, posY + 30);
            }
            else {
                QFont uncheckedFont("Times", 10);
                painter.setFont(uncheckedFont);

                QPen uncheckedPen;
                uncheckedPen.setBrush(QColor(128,128,128));
                painter.setPen(uncheckedPen);
            }
        }

        QIcon icon(actList[i]->icon());
        QRect iconRect(10, posY, 30, 30);
        icon.paint(&painter, iconRect);
        QRect textRect(50, posY + 10, event->rect().width(), event->rect().height());
        painter.drawText(textRect, actList[i]->text());

        posY += 50;
        if(i == 2) {
            QPen checkedPen;  // creates a default pen
            checkedPen.setWidth(2);
            checkedPen.setBrush(Qt::green);
            painter.setPen(checkedPen);
            painter.drawLine(0, 285, 200, 285);

            posY += 50;
        }
    }
}

void Sidebar::paintStatus(QPainter &painter)
{
    if(Inbox::inboxNum > 0) {
        QRect textRect(150, 120, 30, 30);
        painter.setPen(Qt::red);
        painter.drawText(textRect, QString::number(Inbox::inboxNum));
    }
}

void Sidebar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.fillRect(rect(), QColor(240, 248, 255)); //set background color

    paintLogo(painter);
    paintMenu(painter, event);
    paintStatus(painter);
}

void Sidebar::mousePressEvent(QMouseEvent *event)
{
    QAction *action = actionAt(event->pos());

    //specify the sidebar clickable area, to make sure that the sidebar menu will only change in the clickable area
    if((event->pos().y() >= 110 && event->pos().y() <= 260) || (event->pos().y() >= 310 && event->pos().y() <= 410)) {
        checkedAct = action;
    }
    if(checkedAct != NULL) {
        int index = std::find(actList.begin(), actList.end(), checkedAct) - actList.begin();
        emit actionChanged(index);
    }
    update();
}

void Sidebar::mouseMoveEvent(QMouseEvent *event)
{
    QAction *action = actionAt(event->pos());
    hoveredAct = action;
    update();
}
