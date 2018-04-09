/*************************************************************************
	> File Name: 委托与包含.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月09日 星期一 22时11分40秒
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;
class StringRep;
class String
{
public:
    String();
    String(const char * s);
    String(const String& s);
    String &operator = (const String&  s );
    ~String();

private:
    /*
     * 这个写法很好  本体是Handle/   下便是Body
     * 这里边可以随意修改  变动也只需变StringRep 里边的就可以了 
     * 编译防火墙   pimpl 是指针去实现 
     * 此指针将来可以指向其他的类 
     */
    StringRep* rep; //pimpl
};

class StringRep
{
public:
    StringRep();
    ~StringRep();
private:
    char *str;
};

int main()
{
    return 0;
}
