#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;


void * thr_fn1(void *arg){
    cout<<"thread 1 returning"<<endl;
    return ((void*) 0);
}

void * thr_fn2(void *arg){
    cout<<"thread 2 exiting"<<endl;
    sleep(3);
    return ((void*) 1);
}

int main(){
    pthread_t tid1,tid2;
    void * tret;
    pthread_create(&tid1,NULL,thr_fn1,NULL);    // creat thread 1 and 2
    pthread_create(&tid2,NULL,thr_fn2,NULL);
   
    pthread_join(tid1,&tret);                   // 阻塞，知道线程 返回/退出
    cout<<"thread 1: "<<tret<<endl;
    pthread_join(tid2,&tret);                   // 由于thr_fn2，在这里停顿了3秒
    cout<<"thread 2: "<<tret<<endl;


    sleep(1);
    return 0;
}