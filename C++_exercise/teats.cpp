/*************************************************************************
	> File Name: teats.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月22日 星期五 13时44分22秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    char str[16];
    char ptr[16];
    int i=0,j=0;
    for( i=0;i<15;i++){
        cin >> str[i];
        if(str[i]>='a' &&str[i]<='z')
            ptr[j++] = str[i];
    }
    ptr[j] = '\0';
    cout << ptr<<endl;
}


