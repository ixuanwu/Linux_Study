/*************************************************************************
	> File Name: printSig.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 06 May 2014 07:31:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<signal.h>
#include<errno.h>

void pr_mask(const char *str)
{
	sigset_t sigset;
	int errno_save;
	if(sigprocmask(0,NULL,&sigset)<0)
		perror("sigprocmask error ");
	printf("%s",str);
	if(sigismember(&sigset,SIGINT))
		printf("SIGINT\n");
	if(sigismember(&sigset,SIGQUIT))
		printf("SIGQUIT\n");
	if(sigismember(&sigset,SIGUSR1))
		printf("SIGUSR1\n");
	if(sigismember(&sigset,SIGALRM))
		printf("SIGALRM\n");
	printf("\n");
	errno = errno_save;
}
int main()
{
	pr_mask("sigprocmask");
	return 0;
}
