/*************************************************************************
	> File Name: sigwinch.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Wed 07 May 2014 11:31:47 PM CST
 ************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
#include<string.h>
#include<sys/ioctl.h>
#include<termios.h>
//信号处理函数
void sig_deal(int signo);
//设置终端模式
int  set_mode(int flags);
//填充屏幕
int fill_screen();
//全局变量
char ch = 'A';
int main(int argc, char *argv[])
{
	char c;
	int count = 0;
	struct winsize size;
	set_mode(0);
	signal(SIGWINCH,sig_deal);
	fill_screen();
	while((c=getchar())!=EOF)
	{
		if(c=='Q')
		{
			set_mode(1);
			system("clear");
			return 0;
		}
		else
		{
			ch = 'A';
			fill_screen();
		}
	}
	return 0;
}

void sig_deal(int signo)
{
	switch(signo)
	{
		case SIGINT:
			set_mode(1);
			break;
		case SIGQUIT:
			set_mode(1);
			break;
		case SIGWINCH:
			fill_screen();				
			break;
		default:
			break;
	}
}
int fill_screen()
{
	printf("\n");//我也不清楚，为什么添加了这行就输出就行了
	struct winsize size;
	int i;
	if(isatty(STDOUT_FILENO)==0)
	{
		perror("isatty STDOUT_FILENO error");
		return 1;
	}
	if(ioctl(STDOUT_FILENO,TIOCGWINSZ,&size)==-1)
	{
		perror("ioctl STDOUT_FILENO error");
		return 1;
	}
	for(i = 0;i<size.ws_row*size.ws_col;i++)
	{
		putchar(ch);
	}
	//将缓冲区全部输出到终端
	fflush(stdout);
	ch++;
}
int set_mode(int flags)
/*
 * flags = 0表示设置新的终端模式
 * flags = 1表示重置为原来的终端模式
 */
{
	static struct termios oldtm,newtm;
	switch(flags)
	{
		case 0:
			if(tcgetattr(STDOUT_FILENO,&oldtm)==-1)
			{
				perror("tcgetattr STDOUT_FILENO error");
				return 2;
			}
			newtm = oldtm;
			newtm.c_lflag &= ~ICANON;//设置为非规范模式
			newtm.c_lflag &= ~ECHO;//设置终端无回显
			newtm.c_cc[VMIN] = 1;
			if(tcsetattr(STDOUT_FILENO,TCSANOW,&newtm)==-1)
			{
				perror("tcsetattr STDOUT_FILENO error");
				return 3;
			}
			break;
		case 1:
			if(tcsetattr(STDOUT_FILENO,TCSANOW,&oldtm)==-1)
			{
				perror("tcsetattr STDOUT_FILENO error");
				return 3;
			}
			break;
		default:
			break;
	}
}
