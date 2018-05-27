/*************************************************************************
	> File Name: guer.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月12日 星期六 11时11分39秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    pid_t  pid = fork();
    if(pid == 0)
    {
        sleep(1);
        printf("child pid = %d,ppid = %d\n",getpid(),getppid());
    }
    else if(pid >0){
        printf("=========parent\n");
    }
    return 0;
}
