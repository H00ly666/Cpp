/*************************************************************************
	> File Name: read.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 21时46分43秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class CStudent{
    public:
        char  name[20];
        int score;
};


int main()
{
    CStudent S;
    ifstream inFile("1.dat",ios::in|ios::binary);
    if(!inFile){
        cout << "error" <<endl;
        return 0;
    }
    while(inFile.read((char *)&S,sizeof(S))){
        int  nReadBytes = inFile.gcount(); // 看看刚才读了多少个字节
        cout << S.name << "" << S.score <<endl;
    }
    inFile.close();
    return 0;
}
