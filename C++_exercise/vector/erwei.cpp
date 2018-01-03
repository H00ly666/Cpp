/*************************************************************************
	> File Name: erwei.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年01月02日 星期二 17时04分09秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int> >  vv(3,vector<int>(4))  ;    //两个 "> " 之间的空格不可缺少
    for(auto &i : vv)
        vv.push_back(i);
    for(int i=0;i<3 ; i++)
        for(int j=0 ; j<5;j++ )
            cout << vv[i][j] <<endl;
    
}
