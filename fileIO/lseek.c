/*************************************************************************
	> File Name: lseek.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 13时05分23秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1)
        perror("lseek");
    else
        printf("lseek ok!\n");
    return 0;
}
