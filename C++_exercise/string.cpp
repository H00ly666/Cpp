/*************************************************************************
	> File Name: my_String.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月18日 星期一 09时51分40秒
 ************************************************************************/

#include<iostream>
#include<netinet/in.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<assert.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

class my_String
{
    int size1;   //字符个数
    char *ptr;  //指向这个字符串
    friend ostream& operator<<(ostream& os,my_String& str);
    friend istream& operator>>(istream& os,my_String& str);
    public:
       // explicit my_String(const char  *otr);   //显式构造
        my_String(const char *otr) ;   //隐式构造
        my_String(const my_String & str);
        my_String(int h ,char a);
        ~my_String() {if(ptr) delete []ptr;  }
        int size() const {return  size1;}
        char & operator [] (int i )  //重载[]
        {
            return ptr[i];
        }
        my_String & operator = (  my_String &str); // 重载 = 
       // my_String & operator = ( char *str);

};

my_String::my_String(const  char  *otr):size1(strlen(otr))  //可做默认构造函数　　或　my_string(“hhhh”);
{
    if(!otr) {
        ptr = NULL;
    }else{
        ptr =  new char[size1 + 1];
        memcpy( ptr ,otr,size1 + 1);
       // ptr[size1] = '\0';
    }
}

my_String::my_String(const my_String &str):size1(str.size())
{
    if(!str.ptr) 
        ptr = NULL;
    else{
        ptr =  new char [size1 + 1];
        memcpy(ptr, str.ptr, size1+1);
       // ptr[size1] = '\0';
    }
}

my_String::my_String(int h, char a):size1(h)
{
    if(h > 0 ){
        ptr = new  char[h+1];
        for(int  i =0;i<h;i++)
            ptr[i] = a;
        ptr[h] = '\0';
    }else{
        ptr = NULL;
    }
}

//重载= my_String a = b;
my_String& my_String::operator = ( my_String &str)
{
    size1 = strlen(str.ptr);
    ptr  = new char[size1 + 1]; 
    memcpy(ptr,str.ptr,size1+1); 
    
    return *this;
}
//重载＝ my_String a = "1234";
/*
my_String& my_String::operator = ( char * str)
{
    size1 = strlen(str);
    ptr  = new char[size1 + 1]; 
    memcpy(ptr,str,size1+1); 
 
    return *this;
}*/
ostream& operator << (ostream& os,my_String& mtr)  //重载运算符<<   
{  
    os << mtr.ptr;  
    return os;  
} 
istream& operator >> (istream& os,my_String& str)
{
    char temp[255]
    cin >> temp;
    
    return os;
}
int main ()
{
    char  *a = (char*)"helloworld";
   // my_String s  ("hello world");
    my_String s(a);
    // my_String b = my_String("12345");   //重载 =  //显式构造　　
    my_String b = "12345";// 隐式构造
    cout << b.size() <<  b << endl;
    my_String h;
    cin >> h;
    cout<<h<<endl;

}
