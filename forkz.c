/*************************************************************************
	> File Name: forkz.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 22 Apr 2014 09:55:11 AM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"

int main()
{
	pid_t pid;
	if((pid=fork())<0)
	{
		perror("fork error");
	}
	else if(pid==0)
	{
		if((pid=fork())<0)
			perror("fork error\n");
		else if(pid>0)
			exit(0);
		sleep(2);
		printf("second child ,parent pid=%d\n",getppid());
		exit(0);
	}
	if(waitpid(pid,NULL,0)!=pid)
		perror("waitpid error\n");
	return 0;
}	
