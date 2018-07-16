#ifndef MAILPREVIEW_H
#define MAILPREVIEW_H

#include <QWidget>

namespace Ui {
class MailPreview;
}

class MailPreview : public QWidget
{
    Q_OBJECT

public:
    explicit MailPreview(QWidget *parent = 0);
    ~MailPreview();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MailPreview *ui;
};

#endif // MAILPREVIEW_H
