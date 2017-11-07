/*************************************************************************
	> File Name: 16_change.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月01日 星期三 22时58分26秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    const string str = "0123456789ABCDEF";
    cout  << "0-15" <<endl;
    string  result;
    string::size_type n;
    while(cin >> n)
        if  (n < str.size())    // 这里并没有移动result 　的下标　难道result可以自己
            result += str[n];  //string 类型可相加的类型
    }
    cout  <<  result << endl ;
}
