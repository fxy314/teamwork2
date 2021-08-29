#ifndef RECT_H
#define RECT_H

#include <QWidget>

namespace Ui {
class rect;
}

class rect : public QWidget
{
    Q_OBJECT

public:
    explicit rect(QWidget *parent = 0);
    ~rect();

private:
    Ui::rect *ui;
};

#endif // RECT_H
