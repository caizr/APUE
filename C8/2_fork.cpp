/* 创建子进程
*
*
*/
#include<iostream>
#include<unistd.h>

using namespace std;

int main(){
    if(fork() ==0){     //子进程执行
        cout<<"child process"<<endl;
        exit(1);        //如果不用exit，那么下面的语句都会被执行        
    }

    cout<<"test"<<endl;
}