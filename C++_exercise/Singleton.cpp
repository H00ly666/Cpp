/*************************************************************************
	> File Name: Singleton.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月02日 星期一 16时09分34秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
public:
    static A& getInstanse();
    setup() { ... }

private:
    A();
    A(const A& rhs);
    ...
};

A& A::getInstanse()
{
    static A a;
    return a;
}

int main ()
{
    /*
     *单例模式 用这种方式来获取 自身
     * 只有一例
     *
     */
    A::getInstanse().setup();  
}
