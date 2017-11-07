/*************************************************************************
	> File Name: 3.15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 09时34分34秒
 ************************************************************************/

#include<iostream>
#include <vector>
#include <string>
using namespace std;
int main ()
{
    string  str;
    vector<string> svec;
    while (cin >> str &&  str != "123"  ) {
        svec.push_back(str);
    }
    cout << "其中个数"  << svec.size() <<endl;
    for (int i=0; i < svec.size() ;i++)   //  这里似乎需要显示的给i 赋初始值
        cout << svec[i] <<endl;

}
