/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 21时59分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
void swap(int  &a ,int  &b)
{
    int  temp;
    temp = a;a =b ;b =temp;
}


int main()
{
    int a=4,b=3;
    swap(a,b);
    printf("%d %d\n",a,b );
}
