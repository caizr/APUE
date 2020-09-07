#include<iostream>
#include<unistd.h>

using namespace std;

int main(){
    cout<<"hello"<<endl;
    execl("./test","echo","echi",(char *)0);
    return 0;
}