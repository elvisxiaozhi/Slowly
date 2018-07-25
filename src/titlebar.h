#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QAction>

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);

private:
    QList<QAction *> actList;
    QAction *checkedAct;
    QAction *hoveredAct;
    QString userName;
    bool isOnline;

    QAction *addAction(const QString &, const QIcon &);
    QAction *actionAt(const QPoint &);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

signals:
    void actionChanged(int);
};


#endif // TITLEBAR_H
