#include<iostream>
#include<unistd.h>
#include<sys/stat.h>

int main(){
    std::cout<<FOPEN_MAX-1<<"and"<<std::endl;
    return 0;
}