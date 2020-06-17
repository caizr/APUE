/*使用mkdir, rmdir创建删除文件夹
*
*/
#include<sys/stat.h>
#include<iostream>
#include<unistd.h>
int main(){
    using namespace std;
    umask(0000);
    //先777再屏蔽
    cout<<"mkdir: "<<mkdir("newFolder",(S_IRWXU|S_IRWXG|S_IRWXO)&(~(S_IXOTH)))<<endl;
    cout<<"rmdir: "<<rmdir("newFolder")<<endl;
    return 0;
}