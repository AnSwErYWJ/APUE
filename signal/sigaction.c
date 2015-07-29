/*************************************************************************
	> File Name: sigaction.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月29日 星期三 21时11分10秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ouch(int sig)
{
    printf("OUCH!-I GOT SIGNAL %d\n",sig);
}

int main(void)
{
    struct sigaction act;
    act.sa_handler=ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags=0;

    sigaction(SIGINT,&act,NULL);

    while(1)
    {
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}

