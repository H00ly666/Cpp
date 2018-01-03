/*************************************************************************
	> File Name: read_tu.cpp
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年01月02日 星期二 22时44分23秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Tu{
    public:
    int vexnum;
    int arcnum;
    vector <vector <int> > arcs; //边集
};
int  main()
{
    Tu   grap;
    int i , j ,length;
    ifstream inFile("123.txt",ios::in );
    inFile>> grap.vexnum >>grap.arcnum   ; 
    cout << "nbiahskf as "<<endl;
    
    cout << grap.vexnum<<" " <<grap.arcnum <<endl  ;
    
    vector <int> lie;
    for (i =1 ;i<=grap.vexnum; i++ )
        lie.push_back(i);
    for (i =1 ;i<=grap.vexnum; i++ )
        grap.arcs.push_back(lie);
    inFile >> i >> j >> length ;
    grap.arcs[i][j] = length;
    cout << grap.arcs.size()<<endl;
}
