/*************************************************************************
	> File Name: exesort.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Mon 12 May 2014 05:37:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
	execlp("/bin/sort","sort",NULL);
}
