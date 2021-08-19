/**
 * @file shape.cpp
 * @author fxy314 付翔宇 u201811690@hust.edu.cn
 * @brief 相关函数的实现
 * @version 0.1
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include"shape.h"
#include <exception>
#include<cstring>

/*————————————————————————以下为shape类）——————————————————————————————*/
/**
 * @brief 创建一个shape类对象
 * @details area 初始化为0.0, length_info, type, area_info均初始化为空字符串
 */
shape::shape()
{
    area =0.0;
    length_info = "";
    type = "";
    area_info = "";
}

/**
 * @brief 将输入的长度单位上设置为厘米
 * @details 只在将长度设置从英寸改变为厘米时调用，由于面积始终用平方厘米表示，
 * 调用时将面积数值除6.4516（6.4516 = 2.54 * 2.54）
 * @note 此函数调用了cut_to_3()函数，多次调用会降低精度，所以应避免在计算前反复更改单位。由于该函数不会改边长，实际使用时，应先创建子类对象，子类对象使用子类的该函数
 * @example 矩形长宽均为1英寸时，面积为6，4516平方厘米，改变单位为厘米时（不改变数值），长宽均变为1厘米，调用该函数，面积变成1平方厘米
 */
void shape::use_centi()
{
    area = cut_to_3((area)/INCH2);
}
/**
 * @brief 将输入的长度单位上设置为英寸
 * @details 只在将长度设置从厘米改变为英寸时调用，由于面积始终用平方厘米表示，
 * 调用时将面积数值乘6.4516（6.4516 = 2.54 * 2.54）
 * @note 此函数调用了cut_to_3()函数，多次调用会降低精度，所以应避免在计算前反复更改单位。由于该函数不会改边长，实际使用时，应先创建子类对象，子类对象使用子类的该函数
 */
void shape::use_inch()
{
    area = cut_to_3((area) * INCH2);
}

/**
 * @brief 返回图形的面积
 * @details 四种图形均用该函数返回面积，面积单位时平方厘米，返回值保留三位小数
 * @return double 面积的数值
 */
double shape::get_area()
{   
    area = cut_to_3(area);
    return area;
}

/**
 * @brief 返回说明面积的字符串
 * @details 返回值只保留三位小数，可用于打印显示计算结果
 * @return string  格式为"面积为XX（数字）平方厘米"
 */
string shape::show_area()
{
    area_info = "面积为" + to_string(cut_to_3(area)) + "平方厘米";
    return area_info;
}

/**
 * @brief 返回说明边长信息的字符串
 * @details 返回值只保留三位小数，可用于打印显示输入
 * @return string  格式为"XX（边）为XX（数字）厘米"，有多条边中间用逗号隔开，"XX（边）为XX（数字）厘米，XX（边）为XX（数字）厘米"
 */
string shape::show_param()
{
    return length_info;
}

/**
 * @brief 返回说明面积大小的字符串
 * @details 返回值只保留三位小数，可用于打印显示选择的图形
 * @return string 格式为“图形种类为：XX”
 */
string shape::show_type()
{
    return type;
}
/**
 * @brief 此静态函数用于将一个double类的数只保留小数点后三位，并返回
 * @details 此函数并未设置输入范围限制，只在面积计算函数中设置了
 * @param origin 输入的浮点数
 * @return double 只保留三位后的结果
 * @note 此函数在其他函数中多次被调用，每次调用都可能会降低计算精度
 */
double shape::cut_to_3(double origin)
{
    long int temp = (long int)(origin * 1000);
    double output = (double(temp)/1000);
    return output;
}


/*————————————————————————————以下为square类——————————————————————————*/
/**
 * @brief Construct a new square::square object
 * @details 继承于shape类的构造函数，只是将type的值更改了
 */

square::square():shape()
{
    type = "图形种类为：正方形";
}

/**
 * @brief 设置正方形参数
 * @details 通过输入确定正方形的边长，同时修改正方形的面积，均只保留三位小数
 * @exception 长度参数必须在设置范围内，即MINVALUE到MAXVALUE之间，否则抛出const char[]异常 ："输入参数错误！"
 * @param input_len 正方形的边长
 */
void square::set_param(double input_len)
{   
    if((input_len - 0 > MINVALUE) && (input_len < MAXVALUE))
    {
        length = cut_to_3(input_len);
        area = cut_to_3(length * length);
        length_info = "该正方形长度为" +  to_string(length) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
}

/**
 * @brief 返回以厘米为单位的正方形边长，保留三位小数
 * @return double 正方形边长
 */
double square::get_length()
{
    return length;
}

/**
 * @brief 用于正方形对象的use_inch()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改边长的功能，正方形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从厘米变为英寸时使用，如果已经选择英寸，再次选择英寸时不能调用，而且不要在厘米与英寸之间反复切换
 */
void square::use_inch()
{
    shape::use_inch();
    length = cut_to_3(length * INCH);
}

/**
 * @brief 用于正方形对象的use_centi()函数
 * @details 该函数继承了shape中原函数更改面积的特点，增加了更改边长的功能，正方形对象应该调用该函数而不是shape类中的原函数
 * @note 该函数只能在单位从英寸变为厘米时使用，如果已经选择厘米，再次选择厘米时不能调用，而且不要在厘米与英寸之间反复切换
 */
void square::use_centi()
{
    shape::use_inch();
    length = cut_to_3(length / INCH);
}

/*——————————————————————————以下为rectangle类————————————————————————————*/
rectangle::rectangle():shape()
{
    type = "图形种类为：长方形";
}

void rectangle::set_param(double input_len, double input_hei)
{   
    if( (input_len - 0 > MINVALUE ) && (input_hei - 0 > MINVALUE) 
    && (input_len < MAXVALUE) && (input_hei < MAXVALUE))
    {
        length = cut_to_3(input_len);
        height = cut_to_3(input_hei);
        area = cut_to_3(length * height);
        length_info = "该长方形长为" + to_string(length) + "厘米，宽为" + to_string(height) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
};

void rectangle::use_centi()
{
    shape::use_centi();
    length = cut_to_3(length * INCH);
    height = cut_to_3(height * INCH);
}

void rectangle::use_inch()
{
    shape::use_inch();
    length = cut_to_3(length / INCH);
    height = cut_to_3(height / INCH);
}

double rectangle::get_length()
{
    return length;
}

double rectangle::get_height()
{
    return height;
}

/*————————————————————————————以下为triangle类————————————————————————————*/
triangle::triangle():shape()
{
    type = "图形种类为：三角形";
}

void triangle::set_param(double input_len, double input_hei)
{
    
    if( (input_len - 0 > MINVALUE ) && (input_hei - 0 > MINVALUE)
    && (input_len < MAXVALUE) && (input_hei < MAXVALUE))
    {
        length = cut_to_3(input_len);
        height = cut_to_3(input_hei);
        area = cut_to_3(length * height / 2);
        length_info = "该三角形底边长为" + to_string(length) + "厘米，该底边上的高为" + to_string(height) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
}

void triangle::use_centi()
{
    shape::use_centi();
    length = cut_to_3(length * INCH);
    height = cut_to_3(height * INCH);
}

void triangle::use_inch()
{
    shape::use_inch();
    length = cut_to_3(length / INCH);
    height = cut_to_3(height / INCH);
}

double triangle::get_length()
{
    return length;
}

double triangle::get_height()
{
    return height;
}

/*————————————————————————————————以下为circile类——————————————————————————————————*/
circle::circle():shape()
{
    type = "图形种类为：圆形";
}

void circle::set_param(double input_d)
{   
    if((input_d - 0 > MINVALUE) && (input_d < MAXVALUE))
    {
        diameter = cut_to_3(input_d);
        area = cut_to_3(pi * diameter * diameter / 4);
        length_info = "该圆的直径为" + to_string(diameter) + "厘米";
    }
    else
    {
        throw "输入参数错误！";
    }
}

void circle::use_centi()
{
    shape::use_centi();
    diameter = cut_to_3(diameter * INCH);
}

void circle::use_inch()
{
    shape::use_inch();
    diameter = cut_to_3(diameter / INCH);
}

double circle::get_diameter()
{
    return diameter;
}


