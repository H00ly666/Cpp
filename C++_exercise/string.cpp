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
    public:
        int size1;   //字符个数
        char *ptr;  //指向这个字符串
        friend ostream& operator<<(ostream& os,my_String& str);
        friend istream& operator>>(istream& os,my_String& str);
        // explicit my_String(const char  *otr);   //显式构造
        my_String();    
        my_String(const char *otr) ;   //隐式构造
        my_String(const my_String & str);
        my_String(int h ,char a);
        ~my_String() {if(ptr) delete []ptr;  }
        int size() const {return  size1;}
        //运算符重载 
        char & operator [] (int i )  {return ptr[i];} //
        my_String & operator = (my_String &str); // 重载 = 
        my_String & operator + (const my_String& str)  ;
      // my_String & operator += (my_String &str);
        //函数重载
        size_t find1(char c , size_t k=0) ; //利用好缺省
        size_t find1(char* str, size_t k = 1);
        size_t find1(my_String &str, size_t k=1);



};
my_String::my_String():size1(0)
{
    ptr = NULL;    
}
my_String::my_String(const  char  *otr):size1(strlen(otr))  //可做默认构造函数　　或　my_string(“hhhh”);
{
    if(!otr) {
        ptr = NULL;
    }else{
        ptr =  new char[size1 + 1];
        memcpy( ptr ,otr,size1 + 1);
    }
}

my_String::my_String(const my_String &str):size1(str.size())
{
    if(!str.ptr) 
        ptr = NULL;
    else{
        ptr =  new char [size1 + 1];
        memcpy(ptr, str.ptr, size1+1);
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
    if(str.ptr == NULL){
        size1 = 0;
        ptr = NULL;
    }else if (ptr ==NULL){
        size1 = strlen(str.ptr);
        ptr = new char [size1+1];
        memcpy(ptr, str.ptr,size1+1 );
    }else{
        delete []ptr;
        size1 = strlen(str.ptr);
        ptr = new char [size1+1];
        memcpy(ptr, str.ptr,size1+1 );
    }
    return *this;
}
my_String& my_String::operator + (const my_String &str)   // a.operator + (b)
{
    my_String* newstring =new my_String;
    if (!str.ptr){
         newstring->ptr = str;
        newstring->size1 = size1;
    }else if (!ptr){
         newstring->  = str;
    }else{
        newstring;
        newstring.ptr = new char[size1+str.size1+1];
        memcpy(newstring.ptr ,ptr ,size1 );
        strcat(newstring.ptr , str.ptr );
        newstring.size1 = size1+str.size1;
    }  
    return newstring;
}
ostream& operator << (ostream& os,my_String& mtr)  //重载运算符<<   
{  
    os << mtr.ptr;  
    return os;  
} 
istream& operator >> (istream& os,my_String& str)
{
    char temp[255];
    cin >> temp;
    str.size1 = strlen(temp);
    str.ptr = new char[str.size1+1];
    memcpy(str.ptr , temp, str.size1);
    return os;
}
//成员函数重载
/*
size_t  my_String::find1 (char c)
{
    size_t  i =0;
    for(i=0 ; i< size1;i++){
        if(ptr[i] == c)
            return  i;
    }
    if(i == size1)
        return -1 ;
}*/
size_t my_String::find1(char c, size_t  k)
{
    if(k <0)
        return -1;
    size_t  i = k;
    for(i ; i< size1;i++){
        if(ptr[i] == c)
            return  i;
    }
    if(i == size1)
        return -1 ; 
}
size_t my_String::find1(char *str,size_t k)
{
    size_t size =strlen(str);
    if(k > size1 || size > size1)
        return -1;
    char *otr = new char[size1-size+1];
    
    memcpy(otr ,ptr+k-1,size1-k+1 );
    
    char *p = strstr(otr,str);
    cout << otr << endl;
    size = p-otr+k-1;
    delete []otr;
    return  size;
}

size_t my_String::find1(my_String &str, size_t k)
{
    int size =strlen(str.ptr);
    if(k > size1)
        return -1;
    char *otr = new char[size1-size+1];
    memcpy(otr ,ptr+k,size1-k+1);
    char *p = strstr(otr,str.ptr);
    
    cout  << otr << " "<< p << endl;
    if(p == NULL)
        return -1;
    size = p-otr+k;
    delete []otr;
    return  size;
}

int main ()
{/*
    char  *a = (char*)"helloworld";
   // my_String s  ("hello world");
    my_String s(a);
    // my_String b = my_String("12345");   //重载 =  //显式构造　　
    my_String b = "12345";// 隐式构造
    cout << b.size() <<  b << endl;
    my_String h;
    cin >> h ;
    cout<< h <<endl;
*/
    my_String a("helloworld");
    my_String b("wor");
   my_String h;
    h= a+b;
    cout<< a.find1(b,5)<< h <<endl;
 
 
    


}
