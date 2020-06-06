/* 使用chmod 修改文件权限
*/


#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    using namespace std;
    struct stat buf;
    lstat("6_3.txt",&buf);
    //添加组的读、写权限
    chmod("6_3.txt",(buf.st_mode)|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    //删除其他的写权限
    chmod("6_3.txt",(buf.st_mode & ~S_IWOTH));
}