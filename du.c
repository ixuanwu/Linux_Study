/*************************************************************************
	> File Name: du.c
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
int print(char *filename,off_t st_size,mode_t mode,int n)
{
	if(S_ISDIR(mode))
	{
		printf("%d\t%s\n",n,filename);
	}
	else
		n = st_size+n;
	return n;
}
int  statis(char *path)
{
	char tempPath[MAX_PATH];
	struct DIR *dir;
	struct dirent *pdirent = NULL;
	struct stat st;
	int nret ;
	int n = 0;
	dir = opendir(path);
	nret = stat(path,&st);
	if(nret==-1)
	{
		show_Error("stat Error");
		return n;
	}
	if(dir!=NULL)
	{
		while((pdirent = readdir(dir))!=NULL)
		{
			if(strcmp(".",pdirent->d_name)==0
					||strcmp("..",pdirent->d_name)==0)
			{
				if(strcmp(".",pdirent->d_name)==0)
					n+=st.st_size;
				continue;
			}
			sprintf(tempPath,"%s/%s",path,pdirent->d_name);
			n+=statis(tempPath);
		}
		closedir(dir);
	}
	return print(path,st.st_size,st.st_mode,n);
}
int main(int argc,char **argv)
{
	if(argc!=1)
	{
		show_Error("请不要输入多余的参数...\n");
		return 1;
	}
	statis(".");
	return 0;
}
