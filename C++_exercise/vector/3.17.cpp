/*************************************************************************
	> File Name: 3.17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 11时37分38秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main ()
{
    string  str;
    vector<string>  svec;
    getline(cin,str);
   // cin >> str;
    for (auto &a : str){
        if( !isspace(a))
            cout << "qwe" <<endl ;
    }
    
    /*
    while (cin >> str && str != "123"){
        svec.push_back(str);
    }
    
    for (auto ptr : svec ){
        for  (auto &c : ptr){
            c = toupper(c);
        }
        cout << ptr <<endl; 
    }*/
}
