/*************************************************************************
	> File Name: uncopy.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 16时07分11秒
 ************************************************************************/

#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MSG_TRY "try again\n"

int main()
{
    char buf[10];
    int fd,n;
    fd = open("/dev/tty",O_RDONLY | O_NONBLOCK);
    if(fd<0)
    {
        perror("open /dev/tty");
        exit(1);
    }
    tryagain:
    n = read(fd,buf,10);
    if(n<0){
        //如果write为非阻塞,但是没有数据可读,此时全局变量errno被设置为EAGAIN
        if(errno == EAGAIN){
            sleep(3);
            write(STDOUT_FILENO,MSG_TRY,strlen(MSG_TRY));
            goto tryagain;
        }
        perror("read /dev/tty");
        exit(1);
    }
    write(STDOUT_FILENO,buf,n);
    close(fd);
    return 0;
}
