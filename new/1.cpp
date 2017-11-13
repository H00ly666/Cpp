/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 22时16分42秒
 ************************************************************************/

#include<iostream>
using namespace std;
typedef struct stu {
    int a;
    struct stu *next;
}NODE;


int  main()
{
    NODE    *p,*b;
    p = new NODE;
    p->a = 5;
    b = new NODE[5];
    (b[1]) .a = 6;

    printf("%d %d\n",p->a, (b[1]).a );

    delete p;
    delete []b;
    
}
