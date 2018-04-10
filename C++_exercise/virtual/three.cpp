/*************************************************************************
	> File Name: three.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月10日 星期二 11时55分06秒
 ************************************************************************/

#include<iostream>
using namespace std;
/*
 * Inheritance with virtual 
 *
 * 抽象出来形状的类
 * 以便其他几何图形进行继承 
 * 
 * 包含纯虚数的  那么这个类就是一个 抽象类
 * 不能实例化 (不不不不能创建他的对象)  
 * 而只能由它去派生子类
 *
 * 子类继承父类的函数调用权
 *
 */
class Shape
{
public:
    /*
     * 后用 const 修饰,   在这个函数内不能修改类内的成员变量
     * 除非那个成员函数 是 mutable 的
     * = 0 表示这个函数是纯虚函数 可以没有定义 只有接口
     * 希望子类一定要重写 (override) 你对他没有默认定义
     */
    
    virtual void  draw() const = 0;   //pure virtual
    
    /*
     * 预设一个默认的函数 
     * 子类如果有更好的想法 可以重写 (override)
     *
     */
    
    virtual void  error(const string& msg); // impure virtual
    
    /*
     * 功能为 为每一个调用的子类设置一个id 
     * 这在base 的角度看来是稳定的  
     * 子类不需要重新定义它 
     * 所以设置为非虚函数
     *
     */
    
    int  objectID() const; // non-virtual

};

class Rectangle: public Shape
{
    
};
class Ellipse: public Shape
{
    
};



int main()
{

}
