/*************************************************************************
	> File Name: Ccar.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月16日 星期四 09时32分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Ctyre {
    public :
        Ctyre(){cout << "Ctyre contructor" <<endl;  }
        ~Ctyre(){cout << "Ctyre destructor" << endl;}

};
class Cengine{
    public :
        Cengine(){cout << "Cengine contructor" << endl; }
        ~Cengine(){cout << "Cengine destructor " << endl;}

};

class Ccar{
    private :
        Cengine engine;
        Ctyre tyre;
    public :
        Ccar() { cout  << "Ccar contructor " << endl ;}
        ~Ccar() { cout << "Ccar destructor " << endl ; }
};


int main ()
{
   Ccar * car;
    //Ccar  car;
    car = new Ccar;   //不会自己主动调用析构　可能与上的内存分配有关
    delete (car);
    return 0 ;
}
