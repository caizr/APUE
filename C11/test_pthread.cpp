/* 测试线程运行顺序，事实上
    每个线程运行的先后顺序是不确定的
*/

#include<iostream>
#include<pthread.h>
#include<unistd.h>


using namespace std;

void * thr_fn1(void * arg){
    while(1){
        cout<<"1"<<endl;;
        sleep(1);
    }
}

void * thr_fn2(void * arg){
    while(1){
        cout<<"2"<<endl;
        sleep(1);
    }
}

int main(){
    pthread_t tid1,tid2;
    tid1=pthread_create(&tid1,NULL,thr_fn1,NULL);
    tid2=pthread_create(&tid2,NULL,thr_fn2,NULL);
    while(1){
        cout<<"0"<<endl;
        sleep(1);
    }
    pause();
    return 0;
}