/*************************************************************************
	> File Name: my_alarm.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Tue 06 May 2014 12:14:32 AM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#include<signal.h>
#include<pwd.h>
static void my_alarm(int signo)
{
	/*switch(signo)
	{
	}*/
	struct passwd *rootptr;
	printf("in signal handler\n");
	if((rootptr=getpwnam("root"))==NULL)
	{
		perror("getpwnam error");
	}
	alarm(1);
}
int main()
{
	struct passwd *ptr;
	signal(SIGALRM,my_alarm);
	alarm(1);
	for(;;)
	{
		if((ptr=getpwnam("jhc"))==NULL)
			perror("getpwnam error");
		if(strcmp(ptr->pw_name,"jhc")!=0)
			printf("return value corrupted!,pw_name=%s\n",ptr->pw_name);
		printf("name %s\n",ptr->pw_name);
	}
	return 0;
}

