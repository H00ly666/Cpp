/*************************************************************************
	> File Name: test.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月21日 星期四 17时43分39秒
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
#include<string>
using namespace std;
class test{
    int  num;
    friend void  print(test &t);
public:
    test(int n){num = n; }
};
void print(test &t)
{
    cout<< num;0
}

int main()
{
    test a(5);
    
}
