/*************************************************************************
	> File Name: signal.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Mon 05 May 2014 11:14:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<signal.h>
#include<stddef.h>
#define TRUE 1
#define FALSE 0
void sig_int(int signo)
{
	switch(signo)
	{
		case SIGINT:
			printf("SIGINT signal received!\n");
			break;
		case SIGUSR1:
			printf("SIGUSR1 signal received!\n");
			break;
		case SIGUSR2:
			printf("SIGUSR2 signal received!\n");
			break;
	}
}
int main(int argc,char * argv[])
{
	signal(SIGINT,sig_int);
	signal(SIGUSR1,sig_int);
	signal(SIGUSR2,sig_int);
	while(TRUE)
		pause();
	return 0;
}
