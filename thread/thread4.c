/*************************************************************************
	> File Name: thread4.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月30日 星期四 11时45分25秒
 ************************************************************************/

/*
 *取消一个线程
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_function(void *arg)
{
    int i,res;
    res=pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    if(res!=0)
    {
        perror("Thread pthread_setcancelstate failed");
        exit(EXIT_FAILURE);
    }
    res=pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
    if(res != 0)
    {
        perror("thread pthread_setcanceltype failed");
        exit(EXIT_FAILURE);
    }

    printf("thread is running\n");
    for(i=0;i<10;i++)
    {
        printf("thread is still running %d\n",i);
        sleep(1);
    }
    pthread_exit(0);
}

int main(void)
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res=pthread_create(&a_thread,NULL,thread_function,NULL);
    if(res != 0)
    {
        perror("Thread creating failed");
        exit(EXIT_FAILURE);
    }

    sleep(3);
    printf("canceling thread...\n");
    res=pthread_cancel(a_thread);
    if(res != 0)
    {
        perror("thread canceling failed");
        exit(EXIT_FAILURE);
    }
    printf("waiting\n");
    res=pthread_join(a_thread,&thread_result);
    if(res!=0)
    {
        perror("thread join failed");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

