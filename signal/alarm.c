/*************************************************************************
	> File Name: alarm.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月29日 星期三 21时04分29秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

static int flag=0;

void ding(int sig)
{
    flag=1;
}

int main(void)
{
    pid_t pid;
    printf("starting!\n");

    pid=fork();
    switch(pid)
    {
        case -1:
        perror("fork failed!");
        exit(1);
        case 0:
        sleep(5);
        kill(getppid(),SIGALRM);//向父进程发信号
        exit(0);
    }

    printf("waiting!\n");
    (void) signal(SIGALRM,ding);

    pause();//城西挂起直到有信号

    if(flag)
        printf("ding\n");

    printf("done\n");
    exit(0);
}
