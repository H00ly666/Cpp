/*************************************************************************
	> File Name: 7.2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 09时36分53秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
class Person
{
    public :
        void name (string a)
        {
            s_Name = a;
            cout << "姓名" << s_Name <<endl;
        }
        void address(string  b)
        {
            s_Address = b;
            cout << "地址"<< s_Address <<endl;
        }
    private:
        string s_Name;
        string s_Address;
};
int  main()
{
    Person  person;
    
    person.name("刘嘉辉");
    person.address("linux 小组");
    
    return  0;
}
