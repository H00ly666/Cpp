/*************************************************************************
	> File Name: ostream.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月28日 星期四 11时44分50秒
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
/*
class student{
    public:
        int  age;
};
ostream&   operator << (ostream& o, const student & s)
{
    o << s.age;
    return  o;
}

*/
int  main()
{
  /*  student s;
    s.age = 5;*/
    int a;
    ostream o;
    o << a;
    //like  cout.operator.<<(s).operator.<<("hello") ;
    //cout << s << "hello";
    return 0;

}
