/*************************************************************************
	> File Name: sysconf.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 04:02:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"

int main()
{
	long id;
	id = sysconf(_SC_SAVED_IDS);
	printf("%ld\n",id);
	printf("The clock_t is %ld\n",sysconf(_SC_CLK_TCK));
	return 0;
}
