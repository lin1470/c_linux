/*************************************************************************
	> File Name: lseek.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月08日 星期二 14时03分19秒
 ************************************************************************/

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
int main(int argc,const char* argv[])
{
    int fd = open("english.txt",O_RDWR);
    if(fd == -1){
        perror("open error");
        exit(1);
    }

    // extend File
    int len = lseek(fd,1000,SEEK_END);
    printf("len = %d\n",len);
    write(fd,"a",1);
    close(fd);
    return 0;
}
