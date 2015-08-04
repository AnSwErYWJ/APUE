/*************************************************************************
	> File Name: lock_test.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月04日 星期二 20时01分52秒
 ************************************************************************/

/*
 *测试一把锁是否被阻塞
 */

#include<stdio.h>
#include<fcntl.h>

pid_t lock_test(int fd,int type,off_t offset,int whence,off_t len)
{
    struct flock lock;
    lock.l_type = type;//F_RDLCK or F_WRLCK
    lock.l_start = offset;
    lock.l_whence = whence;//SEEK_SET,SEEK_CUR,SEEK_END
    lock.l_len = len;

    if(fcntl(fd,F_GETLK,&lock) == -1)
        perror("lock test failed!");

    if(lock.l_type == F_UNLCK)//如果不存在被阻塞的情况，type会被设置为F——UNCLK
        return 0;//不存在，反或0
    return(lock.l_pid);//存在返回持有这把锁的进程ID
}

#define is_read_lockable(fd,offset,whence,len)\
        (lock_test((fd),F_RDLCK,(offset),(whence),(len)) == 0)
#define is_write_lockable(fd,offset,whence,len)\
        (lock_test((fd),F_WRLCK,(offset),(whence),(len)) == 0)
