/*************************************************************************
	> File Name: testmystring.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月25日 星期一 18时40分39秒
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

#include "mystring.h"

int main()
{
    my_String a("helloworld");
    my_String b("gaogaogao");
    my_String h;
    h=a+b;
    a+=b;
   // cout<< a+=b  <<endl;
    cout << a;
}
