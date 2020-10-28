#include<iostream>
#include <signal.h>
#include<unistd.h>
using namespace std;
static void sig_usr(int); /* one handler for both signals */
int main(){
    if(signal(SIGUSR1,sig_usr)==SIG_ERR){
        cout<<"can\' catch SIGUSR1"<<endl;
        exit(0);
    }
    if(signal(SIGUSR2,sig_usr)==SIG_ERR){
        cout<<"can\' catch SIGUSR2"<<endl;
        exit(0);
    }
    for( ; ; )
        pause();
    return 0;
}
static void sig_usr(int signo){
    if(signo == SIGUSR1)
        cout<<"received SIGUSR1"<<endl;
    else if(signo == SIGUSR2)
        cout<<"received SIGUSR2"<<endl;
    else{
        cout<<"recieve other : "<<signo<<endl;
        exit(0);
    }

}