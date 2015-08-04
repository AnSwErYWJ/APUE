/*************************************************************************
	> File Name: lockfile.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月04日 星期二 20时37分18秒
 ************************************************************************/

/*
 *在文件整体上加锁
 */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

/*第一种方法*/
int lockfile(int fd)
{
    struct flock fl;

    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0;

    return (fcntl(fd,F_SETLK,&fl));
}

/*第二种方法*/

int lock_reg(int fd,int cmd,int type,off_t offset,int whence,off_t len)
{
    struct flock lock;
    lock.l_type = type;//F_RDLCK,F_WRLCK,F_UNLCK
    lock.l_start = offset;
    lock.l_whence = whence;/*SEEK_SET,SEEK_CUR,SEEK_END*/
    lock.l_len = len;

    return (fcntl(fd,cmd,&lock));
}

#define write_lock(fd,offset,whence,len)\
    lock_reg((fd),F_SETLK,F_WRLCK,(offset),(whence),(len))

#define lockfile(fd) write_lock((fd),0,SEEK_SET,0)
