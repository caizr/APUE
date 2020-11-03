#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;

void clearn_up(void *);
void * thr_fn1(void *);


int main(){
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,thr_fn1,(void *)0);
    pause();
    return 0;
}


void  clearn_up ( void * arg){
    cout<<"clearn up: "<<(char *)arg<<endl;
    
}



void * thr_fn1(void * arg){
    // cout<<"thread 1 start"<<endl;
    char * s1 = "thread 1 first handler";
    char * s2 = "thread 2 first handler";
    pthread_cleanup_push(clearn_up,s1);
    pthread_cleanup_push(clearn_up,s2);
    if (arg)
        pthread_exit ((void *)1);
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(1);
    pthread_exit ((void *) 0);
}
