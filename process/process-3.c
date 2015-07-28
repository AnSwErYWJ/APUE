/*************************************************************************
	> File Name: process-3.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月28日 星期二 12时36分55秒
 ************************************************************************/

/*
 *exec系列函数使用，以及freopen。
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    char *filename;

    if(argc != 2)
    {
        fprintf(stderr,"Usage:./a.out filename\n");
        exit(1);
    }

    filename = argv[1];

    if(freopen(filename,"r",stdin) == NULL)
    {
        fprintf(stderr,"could not redirect stdin from file %s\n",filename);
        exit(2);
    }

    execl("./upper","upper",(char *)0);
    perror("Could not exec ./upper\n");
    exit(3);
}
