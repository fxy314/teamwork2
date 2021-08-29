#include "rect.h"
#include "ui_rect.h"

rect::rect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rect)
{
    ui->setupUi(this);
}

rect::~rect()
{
    delete ui;
}
