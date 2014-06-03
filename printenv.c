/*************************************************************************
	> File Name: printenv.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 12:26:32 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"

int main(int argc, char *argv[])
{
	int i;
	char **ptr;
	extern char **environ;
	for(i = 0;i<argc;i++)
	{
		printf("argv[%d]:%s\n",i,argv[i]);
	}
	for(ptr=environ;*ptr!=0;ptr++)
		printf("%s\n",*ptr);
	return 0;
}
