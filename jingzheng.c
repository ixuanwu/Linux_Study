/*************************************************************************
	> File Name: jingzheng.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 11:12:21 AM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
static void charatatime(char *);

int main()
{
	pid_t pid;
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
		charatatime("output from child\n");
	else
		charatatime("output from parent\n");
	return 0;
}

static void charatatime(char *str)
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0;)
		putc(c,stdout);
}
