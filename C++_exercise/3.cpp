/*************************************************************************
	> File Name: 3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月02日 星期四 15时59分08秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main ()
{
    int  ia[4] = {1,2,3,:x
                  4};
    using int_arry = int[4];
    typedef int  int_arry[4];

    for  (int_arry *p =ia; p != ia + 3; ++p ){
        for (int  *q = *p; q != *p + 4 ;++q )
            cout << *q << ' ';
    cout<< endl;

    }


}
