/*
 *字符IO
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int	c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF)
			perror("output error");

	if (ferror(stdin))
		perror("input error");

	exit(0);
}
