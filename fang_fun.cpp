/*************************************************************************
	> File Name: fang_fun.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年03月11日 星期日 21时12分27秒
 ************************************************************************/

#include<iostream>
#include<netinet/in.h>
#include<functional>


using namespace std;

template<typename T>  
class display  
{  
public:  
    void operator()(const T &x)  
    {  
        cout<<x<<" ";   
    }   
};   
  
  
int main()  
{  
    int ia[]={1,2,3,4,5};  
    for_each(ia,ia+5,display<int>());   
      
    return 0;   
}   
