/*************************************************************************
	> File Name: command.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 04 May 2014 12:07:41 AM CST
 ************************************************************************/

#include<stdio.h>
#include"apue.h"
#define TOK_ADD 5

#define MAXLINE 100
void do_line(char *);
void cmd_add(void);
int get_token(void);

int main()
{
	char line[MAXLINE];
	while(fgets(line,sizeof(line),stdin)!=NULL)
		do_line(line);
	return 0;
}
char *tok_ptr;/*global pointer for get_token()*/

void do_line(char *ptr)
{
	int cmd;
	tok_ptr = NULL;
	while((cmd=get_token())>0)
	{
		switch(cmd){
		case TOK_ADD:
			cmd_add();
			break;
		} 
	}
}
void cmd_add(void)
{
	int token;
	token = get_token();
	/*rest of processing for this command*/
}

int get_token(void)
{
	/*fetch next token from line pointed to by tok_ptr*/
}
