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
	   ·���ַ����ϲ�;
	    if(direntp����ƥ��)	printf();    
	   searchdir(?,����·��);
	}
	closedir(dir_ptr);
    }
}
