/*************************************************************************
	> File Name: runlimit.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 12时37分36秒
 ************************************************************************/

/*
 *进程资源限制
 */

#include<stdio.h>
#include<sys/resource.h>

int main(void)
{
    struct rlimit r;

    if(getrlimit(RLIMIT_NOFILE,&r)!=0)
        perror("getrlimit error");
    else
        printf("RLIMIT_NOFILE:cur=%ld,max=%ld\n",r.rlim_cur,r.rlim_max);


    struct rlimit rs;
    rs.rlim_cur=r.rlim_cur;
    rs.rlim_max=r.rlim_max;
    if(setrlimit(RLIMIT_NOFILE,&rs)!=0)
        fprintf(stderr,"setrlimit error\n");
    else
        printf("set successfully!\n");

    return 0;
}
