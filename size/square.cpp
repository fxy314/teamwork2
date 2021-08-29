#include "square.h"
#include "ui_square.h"

square::square(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::square)
{
    ui->setupUi(this);
}

square::~square()
{
    delete ui;
}
