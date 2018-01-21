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
    //istream& getline ( istream &is , string &str , char delim );
    while (getline (cin ,line,'$'))
        if (line.size() < 10)
            cout << line <<  endl;

}
