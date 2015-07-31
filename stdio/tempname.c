/*
 *tmpname的变体tempname
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	if (argc != 3)
    {
		fprintf(stderr,"usage: a.out <directory> <prefix>");
        exit(1);
    }
	printf("%s\n", tempnam(argv[1][0] != ' ' ? argv[1] : NULL,
	  argv[2][0] != ' ' ? argv[2] : NULL));

	exit(0);
}
