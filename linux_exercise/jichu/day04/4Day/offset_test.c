/*************************************************************************
	> File Name: offset_test.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月08日 星期二 14时16分23秒
 ************************************************************************/

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main()
{
    if(lseek(0,0,SEEK_CUR)==-1)
        printf("cannot seek!\n");
    else
        printf("seek OK!\n");
    exit(0);
    return 0;
}
