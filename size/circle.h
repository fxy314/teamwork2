#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>

namespace Ui {
class circle;
}

class circle : public QWidget
{
    Q_OBJECT

public:
    explicit circle(QWidget *parent = 0);
    ~circle();

private:
    Ui::circle *ui;
};

#endif // CIRCLE_H
