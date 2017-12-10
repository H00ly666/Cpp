/*************************************************************************
	> File Name: freopen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 19时58分57秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
    int  x,y;
    cin>>x>>y;
    freopen("test.txt","w",stdout); //将标准输出重定向到text.txt文件  w 代表写
    if(y==0)    
        cerr<<"error"<<endl;  // stderr 是直接在屏幕上的  这一点上和out 没有什么区别
    else
        cout<<x/y;
    return 0;



}
