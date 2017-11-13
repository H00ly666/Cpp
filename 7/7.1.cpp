/*************************************************************************
	> File Name: 7.1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月13日 星期一 15时00分12秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Sales_data 
{
    Sales_data();
    string bookNo;
    unsigned units_sold;
    double revenue; //类内部的变量成员不允许在定义时出初始化，必须使用构造函数
};
Sales_data::Sales_data()
{
    units_sold = 0;
    revenue = 0.0;
}

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >>total.units_sold >> total.revenue){
        Sales_data trans;
        while(cin >> trans.bookNo >> trans.units_sold >> trans.revenue){
            if(total.bookNo == trans.bookNo){
               total.units_sold += trans.units_sold;
                total.revenue  += trans.revenue;
            }
            else {
                cout << total.bookNo << " " << total .units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNo << " " << total.units_sold << total.revenue << endl;
    }
    else{
        std::cerr << "No data?" << std::endl;
        return -1;
    }
    return  0;
}
    
