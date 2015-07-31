/*
 *行IO
 */

#include <stdio.h>
#include<stdlib.h>
#define MAXLINE 3

int main(void)
{
	char buf[MAXLINE];

	while (fgets(buf, MAXLINE, stdin) != NULL)
		if (fputs(buf, stdout) == EOF)
			perror("output error");

	if (ferror(stdin))
		perror("input error");

	exit(0);
}
