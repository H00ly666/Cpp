/*************************************************************************
	> File Name: ispunct.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月01日 星期三 22时07分46秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main ()
{
    string s("Hello world !");
   // decltype(s.size()) punct_cnt =0;
   // int  punct_cnt;    //特别大的值是怎么肥事
//    for  (auto c : s){  // 自动轮寻
//        if (ispunct(c))
//            ++punct_cnt;
//    }
//    cout <<punct_cnt 
//         << "punctuation characters in "<< s <<endl;
//
    s = "nihao";
    string s1;
    cout <<s1 <<sizeof(s) << "\0"<< s.size()  << "  "<<s<<endl;
}
