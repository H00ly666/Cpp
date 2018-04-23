/*************************************************************************
	> File Name: 2.c
	> Author: 刘怪怪
	> Mail: 
	> Created Time: 2018年04月23日 星期一 20时44分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()

{
    int a[3][2] = {2,0,1,8};
    char* str = (char*)malloc (sizeof(char)*20);
    strcpy(str,"\0101\\xb2");
    char *ptr;
    printf("%zu %zu %d\n", sizeof(a),sizeof(a[1][1] = 0), a[1][1]);
    printf("%zu %zu\n%s\n ",sizeof(ptr),strlen(str),str);
    return 0;
}
