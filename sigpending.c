/*************************************************************************
	> File Name: sigpending.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 06 May 2014 07:38:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include"apue.h"

static void sig_quit(int);
int main()
{
	sigset_t newmask,oldmask,pendmask;
	if(signal(SIGQUIT,sig_quit)==SIG_ERR)
	{
		perror("signal error");
	}
	/*
	 * Block SIGQUIT and save current signal mask
	 * */
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGQUIT);
	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)<0)
	{
		perror("SIG_BLOCK error");
	}
	sleep(5);
	if(sigpending(&pendmask)<0)
	{
		perror("sigpending error");
	}
	if(sigismember(&pendmask,SIGQUIT))
	{
		printf("\nSIGQUIT pending\n");
	}
	/**
	 *Reset signal mask which unblocks SIGQUIT
	 */
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
	{
		perror("SIG_SETMASK error");
	}
	printf("SIGQUIT unblocked\n");
	sleep(5);
	return 0;
}

static void sig_quit(int signo)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT,SIG_DFL)==SIG_ERR)
		perror("can't reset SIGQUIT");
}
