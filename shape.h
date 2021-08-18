#include<iostream>
using namespace std;
#ifndef SHAPE_H
#define SHAPE_H

class shape
{
protected:
    double area;
    const double inch = 2.54;
public:
    shape();
    void use_inch();
    void use_centi();
    double get_area();
};

class square : public shape
{
private:
    double length;
public:
    square(double input_len);
};

class rectangle : public shape
{
private:
    double length;
    double height;
public:
    rectangle(double input_len, double input_hei);
};

class triangle : public shape
{
private:
    double length;
    double height;
public:
    triangle(double input_len, double input_hei);
};

class circle : public shape
{
private:
    double radius;
    const double pi = 3.14;
public:
    circle(double input_r);
};

#endif
