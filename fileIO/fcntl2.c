/*
 *更改文件状态标志,set_fl(STDOUT_FILENO,O_SYNC);
 */

#include <stdio.h>
#include <fcntl.h>

void set_fl(int fd, int flags) /* flags are file status flags to turn on */
{
	int	val;

	if ((val = fcntl(fd, F_GETFL, 0)) == -1)
		perror("fcntl F_GETFL error");

	val |= flags;		/* turn on flags */

	if (fcntl(fd, F_SETFL, val) == -1)
		perror("fcntl F_SETFL error");
}
