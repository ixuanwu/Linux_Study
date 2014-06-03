/*************************************************************************
	> File Name: fork.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 03:27:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	if((pid=fork())<0)
		perror("fork error");
	if(pid==0)
	{
		printf("child pid is %d\n",getpid());
		printf("parent pid is %d\n",getppid());
		sleep(60);
	}
	else{
		wait(NULL);
		printf("parent pid is %d\n",getpid());
	}
	return 0;
}
