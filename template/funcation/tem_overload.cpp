/*************************************************************************
	> File Name: tem_overload.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年02月23日 星期五 14时59分43秒

    >函数的匹配遵循以下规则
    >1.参数完全匹配的普通函数
    >2.参数完全匹配的函数模板
    >3.实参经过转化的匹配的普通函数
    >4.上面都找不到就会报错

    使用多个参数来避免二义性
************************************************************************/

#include<iostream>
#include<netinet/in.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<assert.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

//函数模板的重载
template <class T >
void print(T arg1,T arg2 )
{
    cout << "tem 1 " <<endl; 
    if  (arg1>arg2 && arg1==arg2 )
        cout<< "max  is  " << arg1 <<endl;
    else 
        cout<< "max  is  " << arg2 <<endl;
        
}
/*
//函数模板的重载
template <class T,class T1 >
void print(T arg1,T1 arg2 )
{
    cout << "tem 2 " <<endl; 
    if  (arg1>arg2 && arg1==arg2 )
        cout<< "max  is  " << arg1 <<endl;
    else 
        cout<< "max  is  " << arg2 <<endl;
        
}*/
// 普通函数
void print(int  arg1, double arg2 )
{
    cout << "function 1 " <<endl; 
    if  (arg1>arg2 && arg1==arg2 )
        cout<< "max  is  " << arg1 <<endl;
    else 
        cout<< "max  is  " << arg2 <<endl;
}        


int main()
{

    int a=2,b=3;
    double  c=32.32;
    print(c,a);
    return 0;

}
