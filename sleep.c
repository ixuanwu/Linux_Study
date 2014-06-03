/*************************************************************************
	> File Name: sleep.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 06 May 2014 06:24:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<signal.h>

void mysleep(int signo)
{
	
}
int main(int argc, char *argv[])
{
	signal(SIGALRM,mysleep);
	alarm(5);
	//pause();
	return alarm(0);
}
