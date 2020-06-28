#include<stdio.h>
#include<stdlib.h>


extern char **environ;

void exhand(){
    printf("handler1! \n");
}
void running(){
    printf("i am running program... \n");
    exit(2);
}
int main(){
    atexit(exhand);
    printf("hello world \n");
    printf(" %s \n",environ[0]);
    printf(" %s \n",environ[1]);
    printf("can you show this? \n");

}