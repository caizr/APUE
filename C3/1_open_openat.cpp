/* open openat 函数的使用 */
#include<fcntl.h>

int main(){
    int fd=open("1.txt",O_CREAT,0664);
    return 0;
}
