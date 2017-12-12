/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 21时59分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
class  App
{
    int&a;
    int&b;
};
void swap(int  &a ,int  &b)
{
    int  temp;
    temp = a;a =b ;b =temp;
}
int  &max(int& a,int& b)
{
    return a>b?a:b;
}

int main()
{
    int a=4,b=3;
    App  h;
    swap(a,b);
    cout<< h.a<<endl;
    
    cout << &a << "  " <<&b <<endl;
    cout<< max(a,b)<<endl;

    cout << &max(a,b)<< sizeof(A) <<endl;
}
