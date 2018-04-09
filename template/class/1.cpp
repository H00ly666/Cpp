/*************************************************************************
	> File Name: 1.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月08日 星期日 17时04分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

template <typename T>
class complex
{
public:
    complex (T r = 0, T i = 0)
        : re (r), im (i)
    {  }
    complex& operator += (const complex&);
    T real () const { return re; }
    T imag () const { return im; }
private:
    T re, im;

    friend complex& _doapl ( complex *, const complex & ) ;
    
};

/*
 * 编译器会自动作 类型推到   
 * argument  deduction 
 */

template <class T>
inline const T& min(const T& a, const T& b)
{
    return  b < a ? b : a; 
}







int main()
{
    /*
     * 模板类的使用 必须绑定类型 
     */
    complex<double>  c1 (2.5,1.5);
    complex<int> c2 (2,6);
    
    complex<int> c;
    c = min(c1, c2);
}






