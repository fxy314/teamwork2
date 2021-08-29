#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QWidget>

namespace Ui {
class triangle;
}

class triangle : public QWidget
{
    Q_OBJECT

public:
    explicit triangle(QWidget *parent = 0);
    ~triangle();

private:
    Ui::triangle *ui;
};

#endif // TRIANGLE_H
