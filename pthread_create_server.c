/*************************************************************************
	> File Name: pthread_create.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Sun 01 Jun 2014 11:08:41 PM CST
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
#define MAXDATASIZE 8192
#define MAXLINE 255
void * function(void *);
void process_cli(int connfd ,struct sockaddr_in caddr);
struct ARG{
	int connfd;
	struct sockaddr_in caddr;//other data
};
int main()
{
	int retval = 0;
	struct ARG *arg;
	int connfd,sockfd;
	struct hostent *hostp;
	char hostname[MAXLINE];
	pthread_t tid;
	int len;
	struct sockaddr_in saddr,caddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(9999);
	saddr.sin_addr.s_addr = inet_addr("192.168.56.101");
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
	listen(sockfd,5);
	while(1){
		printf("等待客户机连接...\n");
		connfd = accept(sockfd,(struct sockaddr* )&caddr,&len);
		arg = (struct ARG *)malloc(sizeof(arg));
		arg->connfd = connfd;
		memcpy((void *)&arg->caddr,&caddr,sizeof(caddr));
		pthread_create(&tid,NULL,function,(void *)arg);
	}
	close(sockfd);
}

void process_cli(int connfd ,struct sockaddr_in caddr)
{
	int num;
	char recvbuf[MAXDATASIZE],sendbuf[MAXDATASIZE],
		 cli_name[MAXDATASIZE];
	printf("You got a connection from %s.\n",inet_ntoa(caddr.sin_addr));
	num = recv(connfd,cli_name,MAXDATASIZE,0);
	if(num==0)
	{
		close(connfd);
		printf("Client disconnected\n");
		return ;
	}
	cli_name[num-1] = '\0';
	printf("Client's name is %s\n",cli_name);
	while(num=recv(connfd,recvbuf,MAXDATASIZE,0))
	{
		recvbuf[num] = '\0';
		printf("Recvived client (%s) message:%s",cli_name,recvbuf);
		int i;
		for(i = 0;i<num;i++)
		{
			if((recvbuf[i]>='a'&&recvbuf[i]<='z')||(recvbuf[i]>='A'&&recvbuf[i]<='Z'))
			{
				recvbuf[i] = recvbuf[i]+3;
				if((recvbuf[i]>'Z'&&recvbuf[i]<'Z'+3)||(recvbuf[i]>'z'))
				{
					recvbuf[i] = recvbuf[i] - 26;
				}
			}
			sendbuf[i] = recvbuf[i];
		}
		sendbuf[num] = '\0';
		send(connfd,sendbuf,strlen(sendbuf),0);
	}
	printf("有客户退出%s:%d\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
	close(connfd);
}


void * function (void * arg)
{
	struct ARG *info ;
	info = (struct ARG*)arg;
	process_cli(info->connfd,info->caddr);
	free(arg);
	pthread_exit(NULL);
}
