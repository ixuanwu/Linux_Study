/*************************************************************************
	> File Name: readdir.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Wed 23 Apr 2014 11:39:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	DIR *dir = NULL;
	struct dirent *pdirent = NULL;
	dir = opendir(argv[1]);
	if(dir==NULL)
		perror(argv[1]);
	while((pdirent=readdir(dir))!=NULL)
		printf("%s\n",pdirent->d_name);
	closedir(dir);
	return 0;
}
