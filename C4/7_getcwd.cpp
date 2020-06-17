/* getcwd(char * buf, size_t size)获取当前工作目录的绝对路径
*
*/
#include<unistd.h>
#include<iostream>

int main(){
    using namespace std;
    char abspath[30]="hello";
    char * curpath = new char[30];
    getcwd(curpath,30);
    cout<<curpath<<endl;
    return 0;
}