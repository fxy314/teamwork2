#ifndef SQUARE_H
#define SQUARE_H

#include <QWidget>

namespace Ui {
class square;
}

class square : public QWidget
{
    Q_OBJECT

public:
    explicit square(QWidget *parent = 0);
    ~square();

private:
    Ui::square *ui;
};

#endif // SQUARE_H
