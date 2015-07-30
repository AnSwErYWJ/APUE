/*************************************************************************
	> File Name: set_signal.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月30日 星期四 08时58分40秒
 ************************************************************************/

/*
 *sigprocmask和sigpending函数的使用
 */

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void sig_quit(int sig)
{
    printf("caught SIGQUIT\n");
    if(signal(SIGQUIT,SIG_DFL)==SIG_ERR)
        perror("can not reset SIGQUIT");
}

int main(void)
{
    sigset_t newmask,oldmask,pendmask;

    if(signal(SIGQUIT,sig_quit) == SIG_ERR)
        perror("can not catch SIGQUIT");

    sigemptyset(&newmask);
    sigaddset(&newmask,SIGQUIT);
    if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
        perror("SIG_BLOCK error");

    sleep(5);

    if(sigpending(&pendmask)<0)
        perror("sigpending error");
    if(sigismember(&pendmask,SIGQUIT))
        printf("\nSIGQUIT pending\n");

    if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
        perror("SIG_BLOCK error");
    printf("SIGQUIT unblocked\n");

    sleep(5);
    exit(0);
    
}

