/*************************************************************************
	> File Name: string.h
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月03日 星期二 15时46分49秒
 ************************************************************************/

#ifndef _STRING_H
#define _STRING_H

class string
{
public:
    /*
     * 类中带有指针 必须包含有这三种函数
     * 赋值构造函数
     */
    String (const char * cstr = 0 );
    /*
     * 拷贝构造函数 接受自己的类型 
     *
     */
    String (const String& str);
    /*
     * 拷贝赋值
     *
     */
    String& operator = (const String& str);
    
    ~String();
    char* get_c_str() const { return m_data; }

private:
    char * m_data;
};

inline 
String::String(const char* cstr = 0)
{
    if ( cstr ){
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else {
        m_data = new char[1];
        *m_data = '\0';
    }
}

/*
 * 拷贝构造函数
 * 可直接调用另一个object 的data 
 * 兄弟之间互为friend
 */

inline
String::String(const String& str)
{
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
}

/*
 * 一定要在operator=检测自我赋值 
 * self assignment
 * 拷贝赋值函数
 * (copy assignment operator)
 * = 操作符重载
 */

inline String&
String::operator = (const String& str)
{
    /*
     * 若有 a = a; 发生时
     * delete 先将 m_data 除掉
     * copy时已经找不到字符串了 
     * 不止是效率 也提高了安全性
     * 传进来引用 当变量用就行  if内为取地址 拿指针
     */
    if(this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
    return *this;
}

/*
 * 析构函数 destructor
 */

inline 
String::~String()
{
    delete[] m_data;
}
/*
 * 重载<< 不能写成成员函数
 * 否则 调用顺序相反 产生冲突 
 *
 */
ostream&
operator << (ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}


#endif
