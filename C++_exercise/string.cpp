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
    friend istream& operator>>(istream& os,my_String& str);
    // explicit my_String(const char  *otr);   //显式构造
    my_String();    
    my_String(const char *otr) ;   //隐式构造
    my_String(const my_String & str);
    my_String(int h ,char a);
    ~my_String() {if(ptr) delete []ptr;  }
    int size() const {return  size1;}
    //运算符重载 
    inline char & operator [] (int i )  {return ptr[i];} //
    my_String & operator = (const my_String &str); // 重载 = 
    my_String operator + (const my_String& str);
    bool  operator == (my_String &str);    
    my_String & operator += (my_String &str);
    //函数重载
    size_t find1(char c , size_t k=0) ; //利用好缺省
    size_t find1(char* str, size_t k = 1);
    size_t find1(my_String &str, size_t k=1);
    bool empty();
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
my_String& my_String::operator = (const my_String &str)
{
    if (this!=&str) //排除复制本身   
    {  
        delete[] ptr;  
        if(!str.size1) size1=0; //为空  
        else  
        {  
            size1 = strlen(str.ptr);
            ptr = new char[strlen(str.ptr)+1];  
            strcpy(ptr,str.ptr);  
        }  
    }  
    return *this;
}
my_String my_String::operator + (const my_String &str)   // a.operator + (b)
{
    if(!str.size1 || !str.size1&&!size1 )
    return *this;
    else if(!size1)
    return str;
    else{
        my_String temp;
        temp.size1 = size1 +str.size1;
        temp.ptr = new char[temp.size1+1];
        strcpy( temp.ptr, ptr );
        strcat(temp.ptr , str.ptr);
        temp.ptr[temp.size1] = '\0';
        return temp;
    }
}
my_String & my_String:: operator += (my_String &str)
{
    if(!str.size1 || !str.size1&&!size1 )
    return *this;
    else if(!size1){
        size1 = str.size1;
        ptr = new char[size1+1];
        memcpy(ptr,str.ptr ,size1+1);
        return *this;
    }
    else{
        char *temp = new char [size1+1];
        memcpy(temp ,ptr,size1+1); 
        size1 = size1 + str.size1;
        ptr = new char[size1+1];
        memcpy(ptr ,temp ,strlen(temp));
        memcpy(ptr+strlen(temp) ,str.ptr , str.size1+1);
        cout << ptr <<  endl;

    }
}

bool my_String::operator == (my_String &str)
{
    if (size1 != str.size1)  
    return false;  
    return strcmp(str.ptr, ptr)?false:true;  
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
bool my_String::empty()
{
    return  (size1 == 0)?1:0; 
}
int main ()
{
    my_String k,m;
    my_String b = "123";
    my_String h("hello");
    my_String w("world");
    my_String q = w;
    my_String a(w);
    cin >> k; //重载 >>
    cout << k  << endl; 
    char ptr[10] = "world";
    h += w;   //helloworld
    cout<<"[]" <<h[2] << "  "  <<  h.find1('l',2) << "   " << h.find1(ptr) << " " << h.find1(w) <<endl ;
    if(h == w) // ==
        cout <<"相等" <<endl;
    else 
        cout << "不相等"<<endl;
    //+
    m = b+h;
    cout <<m <<endl;
    

     cout << h.empty()  << h.size() << h <<endl;
}
