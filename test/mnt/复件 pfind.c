#include<stdio.h>
#include<dirent.h>

main(int ac, char* av[])
{
    searchdir(av[1], ".");
}

void searchdir(?,?)
{
    dir_ptr = opendir(path);
    if(dir_ptr != NULL)
    {
	while((direntp = readdir(dir_ptr)) != NULL)
	{
           . ..
	   路径字符串合并;
	    if(direntp名字匹配)	printf();    
	   searchdir(?,完整路径);
	}
	closedir(dir_ptr);
    }
}
