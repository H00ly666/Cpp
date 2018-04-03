/*************************************************************************
	> File Name: complex.h
	> Author: 刘怪怪
	> Mail:        防卫式的声明
	> Created Time: 2018年04月03日 星期二 14时52分27秒
 ************************************************************************/

#ifndef _COMPLEX_H  //如果没有定义过这个
#define _COMPLEX_H  //那就定义下这个

class complex
{
public:
    complex (double r=0, double i=0)
            : re (r),im (i)
    {  }
    
    complex& operator += (const complex&);
    double real () const { return re; }
    double imag () const { return im; }



private:
    double re,im;

    friend complex& _doapl (complex*, 
                           const complex&);

};

inline complex&
_doapl(complex* ths, const complex& r)
{
    ths->re += r,re;
    ths->im += r.im;
    return *ths;
}

/*
 * 能不能成为inline 结果并不清楚 
 * 只是加入了inline 的队列 结果要看 编译器的处理
 *
 */

inline complex&
complex::operator += (const complex& r)
{
    return _doapl (this, r);
}

/*
 * 全局的函数
 * 产生一个临时对象
 *
 */

inline complex
operator + (const complex& x, const complex y)
{
    return complex ( real (x)+ real (y),
                     imag (x)  imag (y) ) ;     
}

/*
 * 重载输出运算符
 * 右边为输出项不做改变 为const
 * 左边一直在变化 
 * cout << c1 << endl;
 * 所以返回值须为 ostream  
 *
 */

ostream&
operator << (ostream& os , const complex& x)
{
    return  os << '(' << real (x) 
            << imag (x) << ')';
}











#endif
