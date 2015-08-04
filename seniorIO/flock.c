/*************************************************************************
	> File Name: flock.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月04日 星期二 19时46分08秒
 ************************************************************************/

/*
 *加锁或解锁一个文件区域
 */

#include<stdio.h>
#include<fcntl.h>

int lock_reg(int fd,int cmd,int type,off_t offset,int whence,off_t len)
{
    struct flock lock;
    lock.l_type = type;//F_RDLCK,F_WRLCK,F_UNLCK
    lock.l_start = offset;
    lock.l_whence = whence;/*SEEK_SET,SEEK_CUR,SEEK_END*/
    lock.l_len = len;

    return (fcntl(fd,cmd,&lock));
}

#define read_lock(fd,offset,whence,len)\
        lock_reg((fd),F_SETLK,F_RDLCK,(offset),(whence),(len))
#define readw_lock(fd,offset,whence,len)\
        lock_reg((fd),F_SETLKW,F_RDLCK,(offset),(whence),(len))
#define write_lock(fd,offset,whence,len)\
        lock_reg((fd),F_SETLK,F_WRLCK,(offset),(whence),(len))
#define writew_lock(fd,offset,whence,len)\
        lock_reg((fd),F_SETLKW,F_RDLCK,(offset),(whence),(len))
#define un_lock(fd,offset,whence,len)\
        lock_reg((fd),F_SETLK,F_UNLCK,(offset),(whence),(len))
