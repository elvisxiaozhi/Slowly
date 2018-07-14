#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QDockWidget>
#include <QAction>
#include <QObject>

class Sidebar : public QWidget
{
    Q_OBJECT
public:
    Sidebar(QWidget *parent = nullptr);

private:
    QList<QAction *> actList;
    QAction *checkedAct;
    QAction *hoveredAct;
    int inboxNum;

    QAction *addAction(const QString &, const QIcon &);
    QAction *actionAt(const QPoint &);
    void paintLogo(QPainter &);
    void paintMenu(QPainter &, QPaintEvent *);
    void paintStatus(QPainter &);

signals:
    void actionChanged(int);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // SIDEBAR_H
