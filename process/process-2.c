/*************************************************************************
	> File Name: process-2.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月24日 星期五 14时33分08秒
 ************************************************************************/
/*
 *fork的典型用法,复制进程
 *waitpid与wait相比，可以等待一个特定的进程，提供非阻塞的版本。
 */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void)
{
    pid_t new_pid;
    int exit_code;
    
    new_pid = fork();
    
    switch(new_pid)
    {
        /*ERROR*/
        case -1:
            perror("fork failed");
            exit(1);
        /*CHILD*/
        case 0:
            exit_code = 40;
            break;
        /*PARENT*/
        default:
            exit_code=0;
            break;
    }

    /*do sth*/

    /*父进程将自己挂起，等待子进程结束*/
    if(new_pid != 0)
    {
        int stat_val;
        pid_t child_pid;

        child_pid = waitpid(new_pid,&stat_val,WNOHANG);
        if(child_pid != new_pid)
            perror("waitpid failed");

        printf("Child has finished:\nPID = %d\n",child_pid);
        if(WIFEXITED(stat_val))//正常退出为非0值
            printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
        else
            printf("Child exited abnormally!\n");
    }

    exit(exit_code);
}
