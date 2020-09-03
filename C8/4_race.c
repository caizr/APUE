/* 输出两个字符串，
   一个由子进程输出，另一个又父进程输出
   */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

static void chatatatime(char *);
int main(){
    pid_t pid;
    if ((pid=fork())<0){
        // cout<<"fork error !"<<endl;
        printf("fork() error!");
        exit(0);
    }
    else if (pid == 0){
        // cout<<"output from child"<<endl;
        chatatatime("output from child \n");
        exit(0);
    }
    else {
        // cout<<"output from parent"<<endl;
        chatatatime("output from parent \n");

    }

    return 0;
}

static void chatatatime(char *str){
    char *ptr;
    int c;
    setbuf(stdout,NULL);
    for (ptr=str; (c = *ptr++) !=0; ){
        putc(c,stdout);
    }
}