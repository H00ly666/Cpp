/*************************************************************************
	> File Name: empty.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年10月24日 星期二 21时42分38秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
    string line ;
    while (getline (cin ,line))
       // if  (! line.empty ())
        if (line.size() < 10)
            cout << line <<  endl;

}
