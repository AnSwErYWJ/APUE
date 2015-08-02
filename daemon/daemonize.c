/*************************************************************************
	> File Name: daemonize.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月02日 星期日 11时15分42秒
 ************************************************************************/

/*
 *初始化守护进程
 */

#include "daemonize.h"
#include<stdio.h>
#include<sys/stat.h>
#include<sys/resource.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<syslog.h>
#include<stdlib.h>

void daemonize(const char *cmd)
{
    int i,fd0,fd1,fd2;
    pid_t pid;
    struct rlimit rl;
    struct sigaction sa;

    /*r将文件模式创建屏蔽字设为0*/
    umask(0);

    /*获取最高文件描述符值*/
    if(getrlimit(RLIMIT_NOFILE,&rl) != 0)
    {
        fprintf(stderr,"%s can not get the file limit\n",cmd);
        return;
    }

    /*创建新会话*/
    if((pid = fork()) == -1)
    {
        perror("fork failed");
        return;
    }
    else if(pid != 0)
            exit(0);
    setsid();

    /*避免取得控制终端*/
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGHUP,&sa,NULL) == -1)
    {
        perror("can not ignore SIGHUP");
        return;
    }
    if((pid = fork()) == -1)
    {
        perror("fork failed");
        return;
    }
    else if(pid != 0)
            exit(0);
    
    /*将当前工作目录更换为根目录*/
    if(chdir("/") == -1)
    {
        perror("can not change directory to /");
        return;
    }

    /*关闭不需要的文件描述符*/
    if(rl.rlim_max == RLIM_INFINITY)
        rl.rlim_max = 1024;
    for(i = 0;i < rl.rlim_max;i++)
        close(i);

    /*将文件描述父0，1，2定向到/dev/null上*/
    fd0=open("/dev/null",O_RDWR);
    fd1=dup(0);
    fd2=dup(0);

    /* 初始化日志文件*/
    openlog(cmd,LOG_CONS,LOG_DAEMON);
    if(fd0 != 0||fd1 != 1||fd2 != 2)
    {
        syslog(LOG_ERR,"unexpected file descriptors %d %d %d.",fd0,fd1,fd2);
        exit(1);
    }
}


