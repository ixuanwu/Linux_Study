/*************************************************************************
	> File Name: pfind.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Thu 03 Apr 2014 02:46:51 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#define MAX_LEN 1024
#define MAX_PATH 1024

void show_Error(char *str)
{
	perror(str);
}

void  search(char *path,char *filename)
{
	char tempPath[MAX_PATH];
	struct DIR *dir;
	struct dirent *pdirent = NULL;
	dir = opendir(path);
	if(dir!=NULL)
	{
		while((pdirent = readdir(dir))!=NULL)
		{
			if(strcmp(".",pdirent->d_name)==0
					||strcmp("..",pdirent->d_name)==0)
				continue;
			if(strcmp(pdirent->d_name,filename)==0)
			{
				printf("%s/%s\n",path,filename);
			}
			sprintf(tempPath,"%s/%s",path,pdirent->d_name);
			//printf("%s\n",tempPath);
			search(tempPath,filename);
		}
		closedir(dir);
	}
}
int main(int argc,char **argv)
{
	char fileName[MAX_LEN];
	if(argc!=2)
	{
		show_Error("输入参数错误:usage:pfind filename");
		return 1;
	}
	strcpy(fileName,argv[1]);
	search(".",fileName);
	return 0;
}
