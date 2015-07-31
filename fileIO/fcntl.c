/*
 *fcntl取得文件状态标志
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int	val;

	if (argc != 2)
    {
		fprintf(stderr,"usage: a.out <descriptor#>\n");
        exit(1);
    }

	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1)
    {
        fprintf(stderr,"%d can not GETFL\n",atoi(argv[1]));
        exit(2);
    }

    /*取得访问模式*/
	switch (val & O_ACCMODE) 
    {
	    case O_RDONLY:
		printf("read only");
		break;

	    case O_WRONLY:
		printf("write only");
		break;

	    case O_RDWR:
		printf("read write");
		break;

	    default:
		fprintf(stderr,"unknown access mode\n");
        exit(3);
	}

	if (val & O_APPEND)
		printf(", append");

	if (val & O_NONBLOCK)
		printf(", nonblocking");

    #if defined(O_SYNC)
	if (val & O_SYNC)
		printf(", synchronous writes");

    #endif

	putchar('\n');
	exit(0);
}
