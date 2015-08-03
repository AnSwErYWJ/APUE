/*
 *设置非阻塞IO的两种方式
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*通过更改已经打开的文件描述符的文件状态标志*/
static int flags = O_NONBLOCK;
void set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
	int	val;

	if ((val = fcntl(fd, F_GETFL, 0)) == -1)
		perror("fcntl F_GETFL error");

	val |= flags;		/* turn on flags */

	if (fcntl(fd, F_SETFL, val) == -1)
		perror("fcntl F_SETFL error");
}

/*打开文件时直接指定NONBLOCK标志*/
void my_open(const char *filename,int flag)
{
    if(open(filename,O_RDWR|O_NONBLOCK) == -1)
    {
        perror("open with NONBLOCK failed");
        exit(1);
    }
}
