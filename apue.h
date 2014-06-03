/*************************************************************************
	> File Name: apue.h
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 22 Apr 2014 01:06:12 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
void pr_exit(int status)
{
	if(WIFEXITED(status))
	{
		printf("normal temination,exit status = %d\n",WEXITSTATUS(status));
	}
	else if(WIFSIGNALED(status))
		printf("abnormal temination ,signal number =%d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP 
				WCOREDUMP(status)?"(core file generated)":"");
#else
		"");
#endif
		else if(WIFSTOPPED(status))
			printf("child stopped, signal number = %d\n",WSTOPSIG(status));
}
