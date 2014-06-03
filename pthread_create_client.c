/*************************************************************************
	> File Name: pthread_create_client.c
	> Author: jianghechao
	> Mail: 591378033@qq.com 
	> Created Time: Mon 02 Jun 2014 12:49:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<string.h>
#define MAXDATASIZE 8192
#define PORT 9999
void process(FILE *fp,int sockfd);
char * getMessage(char* sendline,int len,FILE *fp);

int main()
{
	int sockfd;
	struct hostent *he;
	struct sockaddr_in server;
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket error");
		return 1;
	}
	memset(&server,0,sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr("192.168.56.101");
	connect(sockfd,(struct sockaddr*)&server,sizeof(server));
	process(stdin,sockfd);
	close(sockfd);
}

void process(FILE * fp,int sockfd)
{
	char sendline[MAXDATASIZE],recvline[MAXDATASIZE];
	int num;
	printf("Connected to server...\n");
	printf("Input client's name:");
	if(fgets(sendline,MAXDATASIZE,fp)==NULL)
	{
		printf("\nEXIT\n");
		return;
	}
	send(sockfd,sendline,strlen(sendline),0);
	while(getMessage(sendline,MAXDATASIZE,fp)!=NULL)
	{
		send(sockfd,sendline,strlen(sendline),0);
		if((num=recv(sockfd,recvline,MAXDATASIZE,0))==0)
		{
			printf("Server Terminated\n");
			return ;
		}
		recvline[num] = '\0';
		printf("Server Message:%s",recvline);
	}
	printf("\nExit\n");
}

char * getMessage(char *sendline,int len,FILE *fp)
{
	printf("Input string to server:");
	return fgets(sendline,MAXDATASIZE,fp);
}
