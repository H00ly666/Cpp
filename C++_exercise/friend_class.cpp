/*************************************************************************
	> File Name: friend_class.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 20时20分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

class CCar{ 
    private:
        int price;
    public:
 //       CCar(price);
    friend class CDriver;   //声明CDriver 为友元类
};
//CCar::CCar(1000);
class CDriver{
    public :
        CCar mycar;
        void ModifyCar(){     //
            mycar.price += 1000;  //CDriver 是　CCar 的友元类->可以访问其私有成员
        }
};

int  main ()
{

    return 0;
}
