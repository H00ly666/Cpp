/*************************************************************************
	> File Name: 3.21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 22时17分44秒
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;
int main ()
{
    vector<int> text;
    int  x;
    while(cin >> x){
        text.push_back(x);
    }
    for(auto it = text.begin() + 1 ; it != text.end(); ++it ){
        auto c = *it + *(it -1);
        cout << c << endl;
    }
    return 0;
}
