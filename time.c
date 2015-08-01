/*************************************************************************
	> File Name: time.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年07月31日 星期五 19时20分21秒
 ************************************************************************/

/*
 *一系列时间函数
 */

#include<stdio.h>
#include<time.h>
#include<sys/time.h>//gettimeofday

char *week[]={
    "SUNDAY",
    "MONDAY",
    "THESDAY",
    "WEDNESDAY",
    "THURSDAY",
    "FRIDAY",
    "SATURDAY"
};

int main(void)
{
    /*time*/
    time_t t;
    printf("time: %lds\n\n",time(&t));
    
    /*gettimeofday*/
    struct timeval st;
    gettimeofday(&st,NULL);
    printf("gettimeofday: %lds %ldus\n\n",st.tv_sec,st.tv_usec);
    
    /*gmtime和localtime*/
    struct tm *p;
    p=gmtime(&t);
    char *daylight=p->tm_isdst?"summer":"winter";
    
    printf("gmtime:\n");
    printf("daylight: %s\n",daylight);
    printf("Today is the NO.%d day of this year\n",((p->tm_yday)+1));
    printf("%d-%d-%d %s\n",((p->tm_year)+1900),((p->tm_mon)+1),p->tm_mday,week[p->tm_wday]);
    printf("%dh:%dm:%ds\n\n",p->tm_hour,p->tm_min,p->tm_sec);
    
    p=localtime(&t);
    char *daylight1=p->tm_isdst?"summer":"winter";
    
    printf("localime:\n");
    printf("daylight: %s\n",daylight1);
    printf("Today is the NO.%d day of this year\n",((p->tm_yday)+1));
    printf("%d-%d-%d %s\n",((p->tm_year)+1900),((p->tm_mon)+1),p->tm_mday,week[p->tm_wday]);
    printf("%dh:%dm:%ds\n\n",p->tm_hour,p->tm_min,p->tm_sec);
    
    /*mktime*/
    printf("mktime:%lds\n\n",mktime(p));
    
    /*asctime and ctime*/
    printf("asctime: %s\n\n",asctime(p));
    printf("ctime: %s\n\n",ctime(&t));
    
    /*strftime*/
#define MAX 128
    char buf[MAX];
    printf("strftime:\n");
    strftime(buf,MAX,"NOW is %Y/%m/%d %H:%M:%S\n",p);
    fputs(buf,stdout);

    return 0;
    
}
