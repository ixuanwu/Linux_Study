/*************************************************************************
	> File Name: explain.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 07:30:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0)
	{
		if(execl("/home/Linux_Unix/testinterp","testinterp","myarg1","MY ARG2",(char*)0)<0)
			perror("execl error");
	}
	if(waitpid(pid,NULL,0)!=pid)
		perror("waitpid error");
	return 0;
}
