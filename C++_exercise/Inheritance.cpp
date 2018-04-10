/*************************************************************************
	> File Name: Inheritance.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月10日 星期二 10时51分04秒
 ************************************************************************/
/*
 * Inheritance 继承
 *
 */
#include<iostream>
using namespace std;

/*
 * Derived object 
 * -----------------
 * | -----------   |
 * | |Base part|   |
 * | -----------   |
 * -----------------
 */
struct _List_node_base
{
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
    
    /*
     * 构造函数由内而外 首先调用base的 默认构造函数
     * 
     *
     */
    _List_node_base()


    /*
     * 析构函数由外而内
     * 作为 base 的析构函数必须为虚函数 
     * 否则会出现 undefined behavior 
     */
    ~_List_node_base();
};

/*
 * Inheritance 继承
 * 三种继承 表示 is-a
 * public private protected
 */

template <typename _Tp>
struct _List_node : public _List_node_base
{
   _Tp _M_data; 
}

int main()
{

}

