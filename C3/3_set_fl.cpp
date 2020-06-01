/*  修改文件描述符的文件状态标志 
* void set_fl(int fd,int flags);
*/
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

//添加标志位
void set_fl(int fd,int flags){
    int val;
    if(  (val = fcntl(fd,F_GETFL,0)) <0 ){
        std::cout<<"getFL error!"<<std::endl;
    }
    //这里使用或操作，如果直接 F_SETFL 使用flags会出问题
    val |= flags;
    if(fcntl(fd,F_SETFL,val)<0){
        std::cout<<"setfl error!"<<std::endl;
    }
}
//清楚标志位
void clr_fl(int fd,int flags){
    int val,put;
    if(  (val = fcntl(fd,F_GETFL,0)) <0 ){
        printf("fcntl read fd error!");
    }
    //对flags反码去与操作，去除标志
    val &= ~flags;
    if((put=fcntl(fd,F_SETFL,val))<0){
        std::cout<<"clear error!"<<std::endl;
    }
    printf("%d \n",put);
}

int main(int argc,char **argv){
    int val,fd,flags;
    if(argc!=3){
        printf("usage error: program [fd] [flags]");
    }
    //fd=atoi(argv[1]);
    fd=open("1.txt",O_WRONLY);
    if( (val=fcntl(fd,F_GETFL,0)) <0){
        printf("fcntl GETFL error!");
        return -1;
    }
    //打印val（未清除标志位置之前）
    printf("FL of fd: %d \n",val);
    // 输入字符串判断
    if(strcmp(argv[2],"O_RDONLY")==0)
        flags=O_RDONLY;
    else if(strcmp(argv[2],"O_WRONLY")==0)
        flags=O_WRONLY;
    else if(strcmp(argv[2],"O_RDWR")==0)
        flags=O_RDWR;
    else printf("flags ERROR!");
    
    //清除RDWR标志位，应该变成了RDONLY
    //有问题，O_RDWR清除的时候val确实是0，但是再次用fcntl查找还是2
    clr_fl(fd,O_RDWR);
    printf("after clear, FL of fd: %d \n",fcntl(fd,F_GETFL,0));
    return 0;
}