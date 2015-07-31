/*************************************************************************
	> File Name: check_errno.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 10时33分01秒
 ************************************************************************/

/*
 *errno不会为0并且没有出错其值为上次保存的错误值
 */

#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc,const char *argv[])
{
    printf("char *strerror(int errnum);\n");
    fprintf(stderr,"EACCES:%s\n",strerror(EACCES));
    errno=ENOENT;
    printf("void perror(const char *msg);\n");
    perror("argv[0]");
    return 0;
}

