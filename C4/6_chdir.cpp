/* chdir()修改当前进程工作的目录
*
*/
#include<iostream>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    using namespace std;
    cout<<"switch to .. (0 is OK): "<< chdir("..")<<endl;
    cout<<"mkdir: "<<mkdir("CHnewFolder",(S_IRWXU|S_IRWXG|S_IRWXO)&(~(S_IXOTH)))<<endl;
    //cout<<"rmdir: "<<rmdir("newFolder")<<endl;
    return 0;
}