/*************************************************************************
	> File Name: unlink.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Thu 24 Apr 2014 05:11:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	if(open(argv[1],O_RDWR)<0)
		perror("open");
	if(unlink(argv[1])<0)
		perror("unlink");
	printf("file unlinked\n");
	sleep(15);
	printf("done\n");
	return 0;
}
