#include<iostream>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    std::cout<<OPEN_MAX-1<<"and"<<NAME_MAX<<std::endl;
    return 0;
}