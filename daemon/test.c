#include <stdio.h>
#include <stdlib.h>

/*
 *测试程序：ps -ajx
 */

int main(void)
{
    daemonize("dtest");
    while(1)
    {
        sleep(1);
    }
    return 0;
}
