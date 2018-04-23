/*************************************************************************
	> File Name: 14.c
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月23日 星期一 21时26分44秒
 ************************************************************************/

    #include <iostream>

    using namespace std;

   

    int str2int(const char *str)

    {

        int temp = 0;

        const char *ptr = str;  //ptr保存str字符串开头
        if (*str == '-' || *str == '+')  //如果第一个字符是正负号，
       {                      //则移到下一个字符
           str++;
       }
       while(*str != 0)
       {
           if ((*str < '0') || (*str > '9'))  //如果当前字符不是数字
           {                       //则退出循环
               break;
           }
           temp = temp * 10 + (*str - '0'); //如果当前字符是数字则计算数值
           str++;      //移到下一个字符
       }   
       if (*ptr == '-')     //如果字符串是以“-”开头，则转换成其相反数
       {
           temp = -temp;
       }
       return temp;
   }

   int main()
   {
       int n = 0;   

       char p[10] = "";

       cin.getline(p, 20);   //从终端获取一个字符串

       n = str2int(p);      //把字符串转换成整型数

       cout << n << endl;

       return 0;

    }
