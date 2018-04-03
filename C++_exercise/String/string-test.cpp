/*************************************************************************
	> File Name: string-test.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月03日 星期二 15时47分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
    String s1();
    String s2("hello");

    String s3(s1);
    cout << s3 << endl;
    s3 = s2;

    cout << s3 << endl;
}
