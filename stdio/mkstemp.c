/*************************************************************************
	> File Name: mkstemp.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 17时40分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char name[12]="temPXXXXXX";
    int fd;
    if((fd=mkstemp(name)) == -1)
        fprintf(stderr,"mkstemp failed!\n");
    exit(0);
}
