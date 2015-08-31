/*************************************************************************
	> File Name: tcsetattr.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月31日 星期一 16时25分24秒
 ************************************************************************/

/*
 * tcgetattr和tcsetattr演示
 */

#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    struct termios t;

    if(tcgetattr(STDIN_FILENO,&t) < 0)
    {
        perror("tcgetattr failed!");
        exit(EXIT_FAILURE);
    }

    switch(t.c_cflag & CSIZE)
    {
        case CS5:
        printf("5 bits/byte\n");
        break;
        case CS6:
        printf("6 bits/byte\n");
        break;
        case CS7:
        printf("7 bits/byte\n");
        break;
        case CS8:
        printf("8 bits/byte\n");
        break;
        default:
        printf("unkown bits/byte\n");
    }

    t.c_cflag &= ~CSIZE; //clear out the c_cflag
    t.c_cflag |= CS8; //set 8bits/byte

    if(tcsetattr(STDIN_FILENO,TCSANOW,&t) < 0)
    {
        perror("tcsetattr failed!");
        exit(EXIT_FAILURE);
    }

    if(tcgetattr(STDIN_FILENO,&t) < 0)
    {
        perror("tcgetattr failed!");
        exit(EXIT_FAILURE);
    }

    if((t.c_cflag & CSIZE) == CS8)
        printf("set successfully!\n");
    else
        printf("set failed!\n");

    exit(EXIT_SUCCESS);
}
