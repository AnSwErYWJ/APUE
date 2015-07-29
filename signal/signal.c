/*************************************************************************
	> File Name: signal.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月29日 星期三 20时58分05秒
 ************************************************************************/
/*
 *signal只处理一次信号
 */


#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void ouch(int sig)
{
    printf("OUCH!-I GOT SIGNAL %d\n",sig);
    (void)signal(SIGINT,SIG_DFL);
}

int main(void)
{
    if(signal(SIGINT,ouch)==SIG_ERR)
        perror("can not catch SIGINT!\n");

    while(1)
    {
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}
