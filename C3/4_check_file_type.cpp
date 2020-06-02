/*  检查文件类型 */

#include<iostream>
#include<sys/stat.h>
#include<sys/unistd.h>

int main(int argc, char **argv){
    struct stat buf;
    for(int i=1;i<argc;++i){
        if(lstat(argv[i],&buf)<0){
            //异常处理
            std::cout<<"lstat error!"<<std::endl;
        }
        if(S_ISREG(buf.st_mode))
            std::cout<<"regular file"<<std::endl;
        else if(S_ISDIR(buf.st_mode))
            std::cout<<"dictionary"<<std::endl;
        /* FIFO, LINK, SOCKET */
        
    }
    return 0;
}