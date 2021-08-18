class shape_class
{
private:
    int type;
    /* 用数字代表形状，0代表正方形，1代表长方形，
    2代表三角形，3代表圆形 */
    double area;// 面积

public: 
    shape_class(int type_input);
    ~shape_class();
};

shape_class::shape_class(int type_input)
{   type = type_input;
    area = 0.0; //面积初始化为0
}

shape_class::~shape_class()
{
}
