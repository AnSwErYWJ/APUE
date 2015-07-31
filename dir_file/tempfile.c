/*************************************************************************
	> File Name: tempfile.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 15时32分13秒
 ************************************************************************/

/*
 *创建临时文件的一个方法：用open或create创建文件，然后调用unlink，这样在程序运行时文件一直存在，程序退出后，文件也被删除。
 */

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    if(open("tmp.txt",O_RDWR|O_CREAT|O_EXCL|O_TRUNC) == -1)
    {
        perror("create tmp.txt failed");
        exit(1);
    }

    printf("create successfully!\n");
    
    if(unlink("tmp.txt") == -1)
    {
        perror("unlink failed!");
        exit(2);
    }

    printf("unlink successfully!\n");

    sleep(3);

    exit(0);
}
