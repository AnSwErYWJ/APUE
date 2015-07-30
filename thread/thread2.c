/*************************************************************************
	> File Name: thread2.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月30日 星期四 10时29分39秒
 ************************************************************************/

/*
 *信号量操作
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>

sem_t bin_sem;
#define MAX 1024
char work_area[MAX];

void *pthread_function(void *arg)
{
    sem_wait(&bin_sem);//-1
    while(strncmp("end",work_area,3)!=0)
    {
        printf("%ld characters\n",strlen(work_area)-1);
        sem_wait(&bin_sem);
    }
    pthread_exit(NULL);
}

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;

    res=sem_init(&bin_sem,0,0);
    if(res != 0)
    {
        perror("sem init failed");
        exit(EXIT_FAILURE);
    }

    res=pthread_create(&a_thread,NULL,pthread_function,NULL);
    if(res!=0)
    {
        perror("thread create failed");
        exit(EXIT_FAILURE);
    }
    printf("Input some text.end to finish\n");
    while(strncmp("end",work_area,3)!=0)
    {
        fgets(work_area,MAX,stdin);
        sem_post(&bin_sem);//+1
    }
    printf("waiting for thread finish\n");
    res = pthread_join(a_thread,&thread_result);
    if(res != 0)
    {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("thread joined\n");
    sem_destroy(&bin_sem);
    exit(EXIT_SUCCESS);
}
