/*************************************************************************
	> File Name: wait.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 01:03:31 AM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<sys/wait.h>
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
int main()
{
	pid_t pid;
	int status;
	if((pid=fork())<0)
		perror("fork");
	else if(pid==0)
		exit(7);
	if(wait(&status)!=pid)
		perror("wait error");
	pr_exit(status);
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
		abort();
	if(wait(&status)!=pid)
		perror("wait error");
	pr_exit(status);
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
		status /=0;
	if(wait(&status)!=pid)
		perror("wait error");
	pr_exit(status);
	return 0;
}
