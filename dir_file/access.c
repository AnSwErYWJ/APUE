/*
 *文件访问权限测试
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	if (argc != 2)
    {
		fprintf(stderr,"usage: a.out <pathname>\n");
        exit(1);
    }
    if (access(argv[1], R_OK) < 0)
		fprintf(stderr,"access error for %s\n", argv[1]);
	else
		printf("read access OK\n");
	if (open(argv[1], O_RDONLY) < 0)
		fprintf(stderr,"open error for %s\n", argv[1]);
	else
		printf("open for reading OK\n");

	exit(0);
}
