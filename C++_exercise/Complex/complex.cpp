/*************************************************************************
	> File Name: complex.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月02日 星期一 15时42分25秒
 ************************************************************************/

#include<iostream>
using namespace std;

class complex 
{
public:
    /*
     * 两参为默认参数( default argument )
     * 初始化列表 完成初始化  // 效率更高
     * 自动调用  你不能调用
     * { re = r; im = i; }  // assertments( 赋值 )
     *
     */
    complex (double r = 0, double i =0)
        : re (r) , im (i)
    {  }
    /*
     *  complex () : re (0), im (0) {}
     *  在此函数类中不能与一号构造函数同是存在
     *  如 complex a; complex()   ;  编译器可能不知道用哪种构造
     */
    complex& operator += (const complex&);
    /*
     * const member functionas (常量成员函数)
     * 只是获取数据内容 而不改变内容
     *
     * 设计时要考虑 使用者是否改变这个数据
     *
     *
     */   
    double hh() const  { return re ;}
    double real () const { return re; }
    double imag () const { return im; }
    
    ~complex();
private:
    double re, im;

    friend  complex& _doapl (complex *, const complex& );
};



int main()
{
    const complex c1(2,1);
    cout << c1.hh() ;
    
    complex *p = new complex[3]; 
    /*
     * array new  一定要搭配array delete 
     *
     */
    delete[] p; //唤起3次析构函数 不加[]  只有一次 

}
