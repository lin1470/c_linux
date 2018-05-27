#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#include "wrap.h"
#define SERV_PORT 8000
int main()
{
    pid_t pid;
    int lfd,cld;
    struct sockaddr_in serv_addr,clie_addr;
    socklen_t clie_addr_len;

    lfd = Socket(AF_INET,SOCK_STREAM,0);

    bzero(&serv_addr,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    // inet_pto(AF_INET,"192.168.42.100",&serv_addr,sizeof(serv_addr));
    Bind(lfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    Listen(lfd,128);
    clie_addr_len = sizeof(clie_addr);
    cfd = Accept(lfd,(struct sockaddr*)&clie_addr,&clie_addr_len);

    pid = fork();
    if(pid<0)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid ==0)
    {
        close(lfd);
        while(1){
            n = Read(cfd,buf,sizeof(buf));
            if(n==0)
            {
                close(cfd);
                return 0;
            }
            else if (n==-1)
            {
                perror("read error");
                exit(1);
            }
            else{
                for(i=0;i<n;i++)
                    buf[i] = toupper(buf[i]);
                write(cfd,buf,n);
            }
        }
    }
}

