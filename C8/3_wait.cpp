/* 等待子进程结束
* wait(), waitpid()
*/

#include<iostream>
#include<sys/wait.h>
#include<unistd.h>

using namespace std;

int main(){

    if( fork() == 0){   //子进程
        cout<<"child process"<<endl;
        sleep(5);
        exit(0);
    }
    int a;
    pid_t p1=wait(&a);
    cout<<"child PID: "<<p1<<endl;
    return 0;
}