/*************************************************************************
	> File Name: writenoblock.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月03日 星期一 21时14分11秒
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
	int	val;

	if ((val = fcntl(fd, F_GETFL, 0)) == -1)
		perror("fcntl F_GETFL error");

	val |= flags;		/* turn on flags */

	if (fcntl(fd, F_SETFL, val) == -1)
		perror("fcntl F_SETFL error");
}

void clr_fl(int fd, int flags) /* flags are file status flags to turn off */
{
	int	val;

	if ((val = fcntl(fd, F_GETFL, 0)) == -1)
		perror("fcntl F_GETFL error");

	val &= ~flags;		/* turn off flags */

	if (fcntl(fd, F_SETFL, val) == -1)
		perror("fcntl F_SETFL error");
}

char buf[500000];

int main(void)
{
    int ntowrite,nwrite;
    char *ptr;
    
    ntowrite = read(STDIN_FILENO,buf,sizeof(buf));
    fprintf(stderr,"read %d bytes\n",ntowrite);
    
    set_fl(STDOUT_FILENO,O_NONBLOCK);//设置非阻塞标志
    
    ptr=buf;
    while(ntowrite > 0)
    {
        errno = 0;
        nwrite = write(STDOUT_FILENO,ptr,ntowrite);
        fprintf(stderr,"nwrite = %d,errno = %d\n",nwrite,errno);

        if(nwrite > 0)
        {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }

    clr_fl(STDOUT_FILENO,O_NONBLOCK);//清除非阻塞状态标志

    exit(0);
}
