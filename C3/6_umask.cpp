/* umask函数屏蔽权限
*  用户
*  S_IRUSR
*  S_IWUSR
*  S_IXUSR
×  组
*  S_IRGRP
*  S_IWGRP
*  S_IXGRP
×  其他
*  S_IROTH
*  S_IWOTH
*  S_IXOTH
*/
#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IROTH)
int main(){
    using namespace std;
    if(creat("6_1.txt",RWRWRW)<0)
        cout<<"create 6_1.txt error!"<<endl;

    //对之后创建的文件屏蔽其组、其他位的读、写权限
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(creat("6_2.txt",RWRWRW)<0)
        cout<<"create 6_2.txt error!"<<endl;
    if(creat("6_3.txt",RWRWRW)<0)
        cout<<"create 6_3.txt error!"<<endl;
}