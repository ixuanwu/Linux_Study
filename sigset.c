/*************************************************************************
	> File Name: sigset.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 06 May 2014 06:59:27 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<signal.h>
#include<sys/wait.h>
#include<error.h>

#define SIGBA(signo)  ((signo)<=0||(signo)>=NSIG)

int sigaddset(sigset_t *set,int signo)
{
	if(SIGBAD(signo))
	{
		errno=EINVAL;
		return -1;
	}
	*set|=1<<(signo-1);
	return 0;
}
int sigdelset(sigset_t *set,int signo)
{
	if(SIGBAD(signo))
	{
		errno = EINVAL;
		return -1;
	}
	*set&=~(1<<(signo-1));
	return 0;
}
int sigismember(const sigset_t *set, int signo)
{
	if(SIGBAD(signo))
	{
		errno = EINVAL;
		return -1;
	}
	return ((*set&(1<<(signo-1)))!=0);
}
int main()
{

	return 0;
}
