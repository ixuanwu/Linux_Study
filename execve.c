/*************************************************************************
	> File Name: execve.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 12:03:29 PM CST
 ************************************************************************/
#include<stdio.h>
#include<sys/wait.h>

char *env_init[] = {"USER=unknown","PATH=/tmp",NULL};
int main()
{
	pid_t pid;
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
	{
		if(execle("/bin/ls","-l",(char *)0,env_init)<0)
			perror("execle error");
	}
	if(waitpid(pid,NULL,0)<0)
		perror("wait error");
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
	{
		if(execlp("netstat","-a",(char *)0)<0)
			perror("execlp error");
	}
	return 0;
}
