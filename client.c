#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1"
#define CONTROLPORT 9988 //连接时使用的端口
int main() 
{ 
    int client_sockfd; 
    int len; 
    struct sockaddr_in address;//服务器端网络地址结构体 
    int result; 
    char ch[] = "hello server !\n";
    char buf[200] = {0}; 
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);//建立客户端socket 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(SERVER_IP);
    address.sin_port = htons(8100); 
    len = sizeof(address); 
    result = connect(client_sockfd, (struct sockaddr *)&address, len); 
    if(result == -1) 
    { 
         perror("oops: client2"); 
         exit(1); 
    } 
    //第一次读写
    write(client_sockfd, ch, sizeof(ch)); 
    read(client_sockfd, buf, sizeof(buf)); 
    printf("the first time: char from server = %s\n", ch); 
    sleep(15);    
    close(client_sockfd); 
   
    return 0; 
}