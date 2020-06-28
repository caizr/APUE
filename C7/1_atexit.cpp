/* 
* atexit()装载退出函数
*
*/
#include<iostream>
#include<cstdlib>

void handler1(){
    std::cout<<"handler1 "<<std::endl;
}
void handler2(){
    std::cout<<"handler2 "<<std::endl;
}
void handler3(){
    std::cout<<"handler3 "<<std::endl;
}

int main(){
    if(std::atexit(handler1)!=0)
        std::cout<<"atexit handler1 error!"<<std::endl;
    if(atexit(handler2)!=0)
        std::cout<<"atexit handler2 error!"<<std::endl;
    if(atexit(handler3)!=0)
        std::cout<<"atexit handler3 error!"<<std::endl;

    std::cout<<"hello world!"<<std::endl;
    std::exit(0);

}

