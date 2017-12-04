/*************************************************************************
	> File Name: write.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 21时17分03秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

class CStudent{
    public:
        char name[20];
        int  score;
};
int main()
{
    CStudent S;//
    //第一个路径参数有就搜索，没有就创建  ,out重写app追加binary二进制打开
    ofstream Outfile("1.dat",ios::out|ios::binary);//创建一个文件流对象..

    while(cin >>S.name>>S.score){
        if(strcmp(S.name,"exit") == 0)
            break;
        Outfile.write((char*)&S,sizeof(S));  //向里边写数据char*引用,字节数long  unsigned
    }
    Outfile.close();//关文件
    return 0;
}
