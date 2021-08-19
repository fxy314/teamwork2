class shape
{
protected:
    double area;// 面积
    const double inch = 2.54;//1 inch = 2.54 cm

public: 
    shape();
    ~shape();
    double get_area();
};
shape::shape()
{
    area = 0.0; //面积初始化为0
}

shape::~shape()
{
}

double shape::get_area()
{
    return area;
}