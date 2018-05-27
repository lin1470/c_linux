/*************************************************************************
	> File Name: open.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月24日 星期二 10时37分23秒
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,const char* argv[])
{
    int fd = open("hello",O_RDWR | O_CREAT,0777);
    if(fd = -1){
        printf("open file failed!\n");
    }
    close(fd);
    
    return 0;
}
