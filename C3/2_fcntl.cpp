/* 实例程序：打印文件标志 */
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char **argv){
    int val;
    if(argc !=2 ){
        std::cout<<"usage: xxx <descriptor#>"<<std::endl;
    }
    if( (val=fcntl(atoi(argv[1]),F_GETFL,0)) < 0 )
        printf("fcntl error for fd %d",atoi(argv[1]));
    
    switch(val & O_ACCMODE){
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read and write");
            break;
        default:
            printf("unknown mode");
    }

    // 追加模式、同步模式等省略
    return 0;
}