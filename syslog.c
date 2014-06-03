/*************************************************************************
	> File Name: syslog.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Thu 29 May 2014 09:24:22 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<syslog.h>
int main(int argc,char *argv[])
{
	openlog("here",LOG_PID,LOG_USER);
	syslog(LOG_INFO|LOG_LOCAL2,"OK");
	closelog();
	return 0;
}
