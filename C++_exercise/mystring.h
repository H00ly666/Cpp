/*************************************************************************
	> File Name: string.h
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2017年12月25日 星期一 18时37分38秒
 ************************************************************************/

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
        inline char & operator [] (int i )  {return ptr[i];} //
        my_String & operator = ( my_String &&str); // 重载 = 
        my_String operator + (const my_String& str);
        bool  operator == (my_String &str);    
        my_String & operator += (my_String &str);
        //函数重载
        size_t find1(char c , size_t k=0) ; //利用好缺省
        size_t find1(char* str, size_t k = 1);
        size_t find1(my_String &str, size_t k=1);
        //bool empty();
};

