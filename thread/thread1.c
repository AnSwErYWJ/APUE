/*************************************************************************
	> File Name: thread1.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月30日 星期四 10时01分28秒
 ************************************************************************/

/*
 *基本线程操作
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

char message[]="hello.world";

void *thread_function(void *arg)
{
    printf("thread_function is running.argument is %s\n",(char*)arg);
    sleep(3);
    strcpy(message,"Bye!");
    pthread_exit("Thank you");
}

int main(void)
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res=pthread_create(&a_thread,NULL,thread_function,(void *)message);
    if(res!=0)
    {
        perror("thread creating failed!");
        exit(EXIT_FAILURE);
    }
    printf("waiting thread finish...\n");
    res=pthread_join(a_thread,&thread_result);
    if(res!=0)
    {
        perror("pthread join failed");
        exit(EXIT_FAILURE);
    }
    printf("thread joined,it returned %s\n",(char *)thread_result);
    printf("message is now %s",message);
    exit(EXIT_SUCCESS);
}
