/*************************************************************************
	> File Name: 3.14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月06日 星期一 09时23分55秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int  val;
    vector<int> ivec;
    while(cin >>val){
        ivec.push_back(val);
    }
    for (int  i =0; i < ivec.size() ; i++){
        cout << ivec[i] << endl;
    }
    for (auto a : ivec )  
        cout << a <<endl;   //a 会替代为ivec 中的每个元素并依次遍历　
    return  0;


}
