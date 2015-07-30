/*************************************************************************
	> File Name: thread3.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月30日 星期四 10时52分22秒
 ************************************************************************/

/*
 *互斥量
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define MAX 1024
pthread_mutex_t work_mutex;
char work_area[MAX];
int time_to_exit=0;

void *thread_function(void *arg)
{
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while(strncmp("end",work_area,3)!=0)
    {
        printf("You input %ld characters\n",strlen(work_area)-1);
        work_area[0]='\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while(work_area[0] == '\0')
        {
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }
    time_to_exit=1;
    work_area[0]='\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}

int main(void)
{
    int res;
    pthread_t a_thread;
    void *pthread_result;
    res=pthread_mutex_init(&work_mutex,NULL);
    if(res!=0)
    {
        perror("Mutex initialization failed");
        exit(EXIT_FAILURE);
    }

    res=pthread_create(&a_thread,NULL,thread_function,NULL);
    if(res!=0)
    {
        perror("thread create failed");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_lock(&work_mutex);
    printf("input some text,end to finish\n");
    while(!time_to_exit)
    {
        fgets(work_area,MAX,stdin);
        pthread_mutex_unlock(&work_mutex);
        while(1)
        {
            pthread_mutex_lock(&work_mutex);
            if(work_area[0]!='\0')
            {
                pthread_mutex_unlock(&work_mutex);
                sleep(1);
            }
            else
                break;
        }
    }
    pthread_mutex_unlock(&work_mutex);
    printf("waiting for thread to finish\n");
    res = pthread_join(a_thread,&pthread_result);
    if(res!=0)
    {
        perror("thread join failed");
        exit(EXIT_FAILURE);
    }
    printf("thread joined\n");
    pthread_mutex_destroy(&work_mutex);
    exit(EXIT_SUCCESS);
}
