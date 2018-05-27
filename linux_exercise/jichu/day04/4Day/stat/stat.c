/*************************************************************************
	> File Name: stat.c
	> Author: 
	> Mail: 
	> Created Time: 2018年05月09日 星期三 20时26分46秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
    struct stat st;
    int ret = stat("english.txt",&st);
    if(ret == -1){
        perror("stat error");
        exit(1);
    }
    printf("file size = %d\n",(int)st.st_size);
    //文件类型,判断是不是普通该文件
    if((st.st_mode & S_IFMT) == S_IFREG){
        printf("这是一个普通文件!\n");
    }
    //所有者对文件的操作权限
    if(st.st_mode & S_IRUSR){
        printf("   r\n");
    }
    if(st.st_mode & S_IWUSR){
        printf("   w\n");
    }
    if(st.st_mode & S_IXUSR){
        printf("   x\n");
    }
    return 0;
}
