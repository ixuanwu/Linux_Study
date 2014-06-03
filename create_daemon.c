/*************************************************************************
	> File Name: create_daemon.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Thu 29 May 2014 10:15:23 AM CST
 ************************************************************************/

#include<stdio.h>
#define MAXFD 64

void daemon_init(const char *pname,int facility)
{
	int i;
	pid_t pid;
	if((pid=fork())!=0)
	{
		exit(0);
	}
	setsid();
	signal(SIGHUP,SIG_IGN);
	if((pid=fork())!=0)
		exit(0);
	chdir("/");
	umask(0);
	for(i = 0;i<MAXFD;i++)
	{
		close(i);
	}
	openlog(pname,LOG_PID,facility);//用syslogd处理错误
}
