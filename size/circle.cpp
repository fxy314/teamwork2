#include "circle.h"
#include "ui_circle.h"

circle::circle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::circle)
{
    ui->setupUi(this);
}

circle::~circle()
{
    delete ui;
}
