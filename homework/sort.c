/*************************************************************************
	> File Name: sort.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Mon 12 May 2014 12:15:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

#define MAXLEN 256 //每行最大字符数目
#define MAXROW 100 //最大行数

void print(char str[][MAXLEN],int n)
{
	int i = 0;
	for(i = 0;i<n;i++)
	{
		printf("%s",str[i]);
	}
}
//准备排序做相关重定向操作
void prepare_sort(int insort[], int outsort[])
{
	if(close(insort[1])==-1)//设置
	{
		perror("close error");
		return;
	}
	if(dup2(insort[0],0)==-1)
	{
		perror("dup2 error");
		return;
	}
	close(insort[0]);
	if(close(outsort[0])==-1)
	{
		perror("close error");
		return;
	}
	if(dup2(outsort[1],1)==-1)
	{
		perror("dup2 error");
		return;
	}
	close(outsort[1]);
	execl("/bin/sort","sort",NULL);
	perror("execlp error");
	return;

}
void sort(char str[][MAXLEN],int n)
{
	int insort[2];
	int outsort[2];
	int i = 0;
	pipe(insort);
	pipe(outsort);
	if(fork()==0)
	{
		prepare_sort(insort,outsort);
	}
	else{
		FILE *filein;
		FILE *fileout;
		char temp[100];
		close(insort[0]);
		filein = fdopen(insort[1],"w");
		
		close(outsort[1]);
		fileout = fdopen(outsort[0],"r");
		for(i = 0;i<n;i++)
		{
			fputs(str[i],filein);
		}
		fclose(filein);
		wait(NULL);
		i = 0; 
		while(fgets(str[i],MAXLEN,fileout)!=NULL)
		{
			i++;
		}
		fclose(fileout);
	}

}
/*
 *从标准输入读取字符串，存到字符串数组中
 * */
int read_str(char str[][MAXLEN])
{
	int i = 0;
	while(fgets(str[i],MAXLEN,stdin)!=NULL)
	{
		i++;
	}
	return i;
}
int main(int argc,char *argv[])
{	
	int length;//字符串个数
	char str[MAXROW][MAXLEN] = {0};//定义一个字符串数组
	length = read_str(str);//从标准输入读取字符串
	sort(str,length);//对读取到的字符串数组进行排序
	printf("排序后:\n");
	print(str,length);//输出排序后的字符串
	return 0;
}
