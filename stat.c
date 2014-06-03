/*************************************************************************
	> File Name: stat.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Thu 10 Apr 2014 10:19:51 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
int main()
{
	DIR *dir ;
	struct dirent *pdir;
	struct stat st;
	dir = opendir(".");
	while(pdir=readdir(dir))
	{
		stat(pdir->d_name,&st);
		printf("%s\n",pdir->d_name);
		printf("dev-t=%d\n",st.st_dev);
		printf("ino_t=%d\n",st.st_ino);
		printf("nlink_t=%d\n",st.st_mode);
		printf("nlink_t=%d\n",st.st_nlink);
		printf("uid_t=%d\n",st.st_uid);
		printf("gid_t=%d\n",st.st_gid);
		printf("dev_t=%d\n",st.st_rdev);
		printf("off_t=%d\n",st.st_size);
		printf("blksize_t=%d\n",st.st_size);
		printf("blkcnt_t=%d\n",st.st_blocks);
		printf("----------------\n");

	}
	closedir(dir);
	return 0;
}
