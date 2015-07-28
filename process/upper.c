/*************************************************************************
	> File Name: upper.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月28日 星期二 12时44分04秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int ch;
    while((ch =getchar()) != EOF)
        putchar(toupper(ch));
    exit(0);
}
