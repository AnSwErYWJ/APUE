/*************************************************************************
	> File Name: syslimit.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 12时24分09秒
 ************************************************************************/

/*
 *系统资源限制
 */

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    long max = 0;
    max = sysconf(_SC_CLK_TCK);
    if(max == -1)
        fprintf(stderr,"sysconf error\n");
    else
        printf("sysconf--clock ticks:%ld\n",max);

    max = pathconf("/etc/passwd",_PC_LINK_MAX);
    if(max == -1)
        fprintf(stderr,"pathconf error\n");
    else
        printf("pathconf--LINK_MAX:%ld\n",max);

    return 0;

}
