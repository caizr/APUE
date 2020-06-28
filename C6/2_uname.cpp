/* 系统标识
*   utsname结构体
%   gethostname()函数
*/
#include<sys/utsname.h>     // struct utsname
#include<unistd.h>          //gethostname()
#include<iostream>
using namespace std;
int main(){
    // utsname结构体
    struct utsname u1;
    cout<<" uname: "<<uname(&u1)<<endl;
    cout<<" sysname: "<<u1.sysname<<endl;
    cout<<" nodename: "<<u1.nodename<<endl;
    cout<<" release: "<<u1.release<<endl;
    cout<<" version: "<<u1.version<<endl;
    cout<<" machine: "<<u1.machine<<endl;

    // gethostname()函数
    char hostname[_SC_HOST_NAME_MAX];
    cout<<endl<<" gethostname: "<<gethostname(hostname,_SC_HOST_NAME_MAX)<<endl;
    cout<<"_SC_HOST_NAME_MAX: "<<_SC_HOST_NAME_MAX<<endl;
    cout<<"hostname: "<<hostname<<endl;
    return 0;
}