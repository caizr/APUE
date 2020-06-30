/*
*   获取标识符
*/
#include<iostream>
#include<unistd.h>

using namespace std;
int main(){
    cout<<"getpid: "<<getpid()<<endl;
    cout<<"getppid: "<<getppid()<<endl;
    cout<<"geteuid: "<<geteuid()<<endl;
    cout<<"getgid: "<<getgid()<<endl;
    cout<<"getegid: "<<getegid()<<endl;
    return 0;
}