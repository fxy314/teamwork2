#include"shape.h"

shape::shape()
{
    this->area =0.0;
}

void shape::use_centi()
{
    this->area = this->area/(inch*inch);
}

void shape::use_inch()
{
    this->area = this->area*inch*inch;
}

double shape::get_area()
{
    return this->area;
}

square::square(double input_len):shape()
{   
    this->length = input_len;
    this->area = this->length * this->length;
}

rectangle::rectangle(double input_len, double input_hei):shape()
{   
    this->length = input_len;
    this->height = input_hei;
    this->area = this->length * this->height;
};

triangle::triangle(double input_len, double input_hei):shape()
{
    this->length = input_len;
    this->height = input_hei;
    this->area = this->length * this->height / 2;
}

circle::circle(double input_r):shape()
{   
    this->radius = input_r;
    this->area = pi * this->radius * this->radius;
}



