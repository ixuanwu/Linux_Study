/*************************************************************************
	> File Name: system.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 08:28:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include"apue.h"

int system(const char *cmdstring)
{
	pid_t pid;
	int status;
	if(cmdstring==NULL)
		return 1;
	if((pid=fork())<0)
	{
		perror("fork error");
		status = -1;
	}else if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmdstring,(char *)0);
		_exit(127);
	}else{
		while(waitpid(pid,&status,0)<0)
		{
			if(errno!=EINTR){
				status = -1;
				break;
			}
		}
	}
	return status;
}
int main()
{
	int status;
	if((status=system("date"))<0)
		perror("system error");
	pr_exit(status);
	if((status=system("nosuchcommand"))<0)
		perror("system error");
	pr_exit(status);
	if((status=system("who;exit 44"))<0)
		perror("system error");
	pr_exit(status);
	return 0;
}
