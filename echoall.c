/*************************************************************************
	> File Name: echoall.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 07:28:53 PM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"

int main(int argc,char *argv[])
{
	int i;
	for(i = 0;i<argc;i++)
	{
		printf("argv[%d]:%s\n",i,argv[i]);
	}
	return 0;
}

