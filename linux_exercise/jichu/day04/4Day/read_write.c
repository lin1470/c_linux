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
    printf("fd = %d\n",fd);
    // open another file,and doing writing
    int fd1 = open("temp",O_WRONLY | O_CREAT,0664);
    printf("fd1 = %d\n",fd1);
    // read
    char buf[4096];
    int len = read(fd,buf,sizeof(buf));
    
    while(len>0){
        //write data into file
        int ret = write(fd1,buf,len);
        printf("ret = %d\n",ret);
        // read
        len = read(fd,buf,sizeof(buf));
    }
    close(fd);
    close(fd1);
    return 0;
}
