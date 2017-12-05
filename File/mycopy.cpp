/*************************************************************************
	> File Name: mycopy.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月05日 星期二 22时09分40秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class CStudent
{
    public :
        char name[20];
        int score;
};    

int main (int  argc, char *argv[])
{
    if(argc!=  3)
    {
        return 0;
    }
    ifstream  inFile (argv[1],ios::binary|ios::in ); //只读
    if(!inFile){
        return 0;
        inFile.close();
    }
    ofstream outFile(argv[2],ios::binary|ios::out);
    if(!outFile){
        outFile.close();
        return 0;
    }
    char c;
    while(inFile.get(c)) //读取一个字符
        outFile.put(c);  //写入一个字符
    outFile.close();
    inFile.close();
    return 0;
}
