/*************************************************************************
	> File Name: change_index.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月11日 星期一 18时08分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class CArray {
        int  size;//数组元素的个数
        int  *ptr;//指向动态分配的数组
    public:
        CArray(int s=0);//s代表数组元素的个数  普通构造函数
        CArray(CArray &a); //复支？   赋值构造函数
        ~CArray();
        void push_back(int v);//用于在数组尾部添加一个元素v
        CArray &operator=(const CArray &a);
        //用于数组对象间的赋值
        int length() {return size;}//返回数组元素的个数
        int&  operator [](int  i )
        {
            return  ptr[i];
        }
};
CArray::CArray(int s):size(s)
{
    if(s==0)
        ptr = NULL;
   else
        ptr = new int[s];
}
CArray::CArray(CArray &a)
{
    if(!a.ptr){
        ptr = NULL;
        size  = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr,a.ptr,sizeof(int)*a.size);
    size = a.size;
}
CArray::~CArray()
{
    if(ptr) delete[] ptr;
}
CArray &CArray::operator = (const CArray &a)
{//赋值号的作用是使“=”左边对象里存放的数组，大小和内容都和右边的对象都一样
    if(ptr==a.ptr)
        return *this;
    if(a.ptr==NULL){//如果a里数组为空
        if(ptr) delete []ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    if(size <a.size){
     if(ptr)
        delete[] ptr;
     ptr= new int[a.size];
    }
    memcpy(ptr,a.ptr,sizeof(int)*a.size);
    size = a.size;
    return *this;
}



void CArray::push_back(int v)
{
    if(ptr){
        int *tmpPtr = new int[size+1];  //重新分配空间 
        memcpy(tmpPtr,ptr,sizeof(int) *size); //拷贝数组原内容
        delete []ptr;
        ptr  = tmpPtr;
    }
    else //数组为空
        ptr = new int[1];
    ptr[size++] = v;  //加入新的数组元素 
}
int  main ()
{
    CArray a;
    for(int  i=0;i< 5;i++)
        a.push_back(i);      //动态来分配内存存放数组元素 需要一个指针成员变量
    CArray a2,a3;
    a2 = a; // =  要重载
    for (int i=0;i<a2.length();i++)
        cout<<a2[i] << " ";   // []要重载
    cout << endl;
    a[3] =100;
    CArray a4(a);    //() 要重载   要自己写复制构造函数 
    for (int  i=0; i<a4.length();i++)
        cout<< a4[i]<< " ";
    cout << endl;
    return 0;
}
