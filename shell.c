/*************************************************************************
	> File Name: shell.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Thu 24 Apr 2014 12:42:08 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define MAXSIZE 100
int main()
{
	char buf[MAXSIZE];
	bzero(buf,sizeof(buf));
	pid_t pid = 0;
	int status;
	printf("%% ");
	while(fgets(buf,MAXSIZE,stdin)!=NULL)
	{
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]='\0';
		if(pid=fork()==0)
		/**
		 * child process do
		 */
		{
			execlp(buf,buf,NULL);
			perror("error");
		}
		/**
		 * parent process do
		 */
		if(waitpid(pid,&status,0)<0)
			perror("waitpid error");
		printf("%% ");
	}

	return 0;
}
