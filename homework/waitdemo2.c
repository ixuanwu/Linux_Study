/*************************************************************************
	> File Name: waitdemo2.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Thu 08 May 2014 05:23:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#define DELAY 30

void child_code(int delay);
void parent_code(pid_t childpid);
void wait_pid(int signo);
int main()
{
	pid_t newpid;
	printf("befor:mypid is %d\n",getpid());
	if((newpid=fork())==-1)
	{
		perror("fork error");
		return 1;
	}
	else if(newpid==0)
	{
		//子进程代码
		child_code(DELAY);
	}else{
		//父进程代码
		signal(SIGCHLD,wait_pid);
		while(1)
		{
			printf("waiting\n");
			sleep(1);

		}
	}
	return 0;
}

/*
 * 子进程代码
 */
void child_code(int delay)
{
	printf("child %d here:will sleep for %d seconds\n",getpid(),delay);
	sleep(delay);
	printf("child done.about to exit\n");
	exit(17);
}

//处理SIGCHLD信号函数
void wait_pid(int signo)
{
	int wait_rv;
	int child_status;
	int high_8,low_7,bit_7;
	wait_rv = wait(&child_status);
	high_8 = child_status>>8;
	low_7 = child_status&0x7F;
	bit_7 = child_status &0x80;
	printf("status:exit = %d,sig = %d, core = %d\n",high_8,low_7,bit_7);
	switch(low_7)
	{
		case SIGINT:
			printf("child exit by SIGINT signal\n");
			break;
		case SIGQUIT:
			printf("child exit by SIGQUIT signal\n");
			break;
		default:
			break;
	}
	exit(0);
}

