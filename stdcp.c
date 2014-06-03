/*************************************************************************
	> File Name: stdcp.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Wed 23 Apr 2014 11:54:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define MAX 100
int main()
{
	int n = 0;
	char buf[MAX];
	while((n=read(STDIN_FILENO,buf,MAX))>0)
	{
		//printf("the bytes have read is %d\n",n);
		buf[n] = 0;//此处一定记得加字符串结尾符
		//printf("The bytes strlen calculate is %d\n",strlen(buf));
		if(write(1,buf,n)!=n)
		{
			perror("write error\n");
		}
		//fflush(stdin);
	}
	if(n<0)
		perror("read error\n");
	return 0;
}
