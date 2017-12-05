/*************************************************************************
	> File Name: modify.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月05日 星期二 21时36分49秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class  CStudent
{
    public:
        char  name[20];
        int   score;
};
int main()
{
    CStudent S;
    
    fstream  iofile("1.dat",ios::app|ios::in|ios::out|ios::binary);   //fsream可读可写
    if(!iofile){
        cout << "error";
        return 0;
    }   
  //  iofile.seekp(2*sizeof(S),ios::beg);  //定位写指针到第三个记录
//    iofile.write("mike",strlen("mike")+1);
    cin >> S.name >> S.score;
    iofile.write((char*)&S,sizeof(S) );

    iofile.seekg(0,ios::beg);   //到开头
    while(iofile.read((char*)&S,sizeof(S)))
        cout<<S.name<<S.score<<endl;
    iofile.close();
}
