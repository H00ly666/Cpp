/*************************************************************************
	> File Name: father_class_protectd.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年01月20日 星期六 21时37分08秒
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

class Father{
private:
    int nprivate;
public:
    int npublic;
protected:
    int nprotectd; //保护成员
};

class Son:public Father(){
    void accessfather(){
        npublic = 1; //ok
        nprivate =1; //wrong
        nprotect = 1; //ok  访问从基继承的proteccted成员
        Son f;
        f.npro tected = 1; // wrong f 不是当前对象
    }
};



int main()
{

}
