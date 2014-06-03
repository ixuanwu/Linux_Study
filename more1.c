/*************************************************************************
	> File Name: more1.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Wed 26 Feb 2014 11:14:18 PM CST
 ************************************************************************/

#include<stdio.h>
#define PAGE_LEN 24
#define LINE_LEN 1024

char get_a_char();
int display_text(FILE * fp ,int num);

int main(int argc,char **argv)
{
	int status = 1;
	FILE *fp;
	char ch;
	char ch1;
	if(argc<=1)
	{
		fp = stdin;
	}
	else
		fp = fopen(argv[1],"r");
	if(fp!=NULL)
	{
		display_text(fp,PAGE_LEN);
		while(status)	
		{
			printf("\033[m----more----\033[m");
			ch = getchar();
			printf("The char is %d\n", ch);
			fflush(stdin);
			switch(ch)
			{
				case ' ':
					status = display_text(fp, PAGE_LEN);
					break;
				case 'n':
					status = display_text(fp, 1);
					break;
				case 'q':
					return 1;
				default:
					break;
			}
		}
	}	
	return 0;
}

char get_a_char()
{
	return getchar();
}

int display_text(FILE *fp,int num)
{
	fflush(stdin);
	int status = 1;
	char buff[LINE_LEN];
	while((fgets(buff,LINE_LEN,fp)!=NULL) && (num>0))
	{
		fputs(buff,stdout);
		num--;
	}
	if(num>0)
		status = 0;
	return status;
}
