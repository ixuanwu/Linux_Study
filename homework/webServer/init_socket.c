/*************************************************************************
	> File Name: init_socket.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Mon 26 May 2014 10:52:31 AM CST
 ************************************************************************/
#include<stdio.h>
#include<sys/socket.h>
#include<sys/param.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netdb.h>
int init_socket(int port_num);
int init_socket(int port_num)
{
	struct sockaddr_in addr;
	int ret_val = 0;
	int length;
	struct hostent * host ;
	int fd;
	char hostname[MAXHOSTNAMELEN];
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port_num);
	ret_val = gethostname(hostname,sizeof(hostname));
	if(ret_val==-1)
	{
		perror("gethostname error");
		return -1;
	}
	host=gethostbyname(hostname);
	if(host==NULL)
	{
		perror("gethostbyname error");
		return -1;
	}
	memcpy((void *)&addr.sin_addr,host->h_addr,host->h_length);
	printf("%s\n",inet_ntoa(addr.sin_addr));
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd==-1)
	{
		perror("socket error");
		return -1;
	}
	printf("socet success\n");
	ret_val = bind(fd,(struct sockaddr *)&addr,sizeof(addr));
	if(ret_val==-1)
	{
		perror("bind error");
		return -1;
	}
	printf("bind success\n");
	if((ret_val=listen(fd,5))==-1)
	{
		perror("bind error");
		return -1;
	}	
	printf("listen success\n");
	return fd;
}
int main()
{
	int fd = init_socket(8080);
	while(1)
	{
		printf("等待客户机连接......\n");
		int cfd = accept(fd,0,0);
		
	}
	return 0;
}

