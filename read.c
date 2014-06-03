/*************************************************************************
	> File Name: read.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 06 May 2014 06:47:18 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#define MAXLINE 100
#include<signal.h>
static void sig_alrm(int signo)
{
	switch(signo)
	{	case SIGALRM:
			printf("SIGALRM signal received\n");
			break;
		default:
			break;
	}
}
int main()
{
	int n;
	char line[MAXLINE];
	if(signal(SIGALRM,sig_alrm)==SIG_ERR)
	{
		perror("signal error");
	}
	alarm(10);
	if(n=read(STDIN_FILENO,line,MAXLINE)<0)
	{
		perror("read error");
	}
	//clear the alarm
	alarm(0);
	write(STDOUT_FILENO,line,n);
	return 0;
}
