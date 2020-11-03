#include<iostream>
#include<unistd.h>
#include<signal.h>
using namespace std;

static void process_alarm(int);
int main(){
    signal(SIGALRM,process_alarm);
    cout<<"test"<<endl;
    alarm(2);
    cout<<"after alarm"<<endl;
    pause();
    cout<<"pause test"<<endl;
    return 0;
}
static void process_alarm(int a){
    cout<<"capture alarm"<<endl;
}