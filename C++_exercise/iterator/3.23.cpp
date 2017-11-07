/*************************************************************************
	> File Name: 3.23.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 22时29分13秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main ()
{
//    vector<int>  ivec{1,2,3,4,5,6,7,8,9,10};
    vector<int>  ivec(10,10);
    int  a;
    while (cin >> a){
        ivec.push_back(a);
    }
    for(auto i= ivec.begin(); i != ivec.end() ; i++){
        (*i) *= 2;
        cout<< *i <<endl;
    }
    
}
