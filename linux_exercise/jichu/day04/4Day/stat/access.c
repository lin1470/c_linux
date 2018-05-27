/*************************************************************************
	> File Name: access.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 21时29分51秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
    if(argc<2){
        printf("a.out Filename\n");
        exit(1);
    }
    int ret = access(argv[1],W_OK);
    if(ret == -1){
        perror("access");
        exit(1);
    }
    printf("you can write this file.n");
    return 0;
}
