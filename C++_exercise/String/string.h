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







#endif
