/*************************************************************************
	> File Name: freopen1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月10日 星期日 20时04分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
int main()
{
    double f;
    int n;
    freopen("t.txt","r",stdin); // cin 从t.txt中读取数据 
    cin>>f>>n;
    cout<<f<<"," << n<<endl;
    return 0;
}
