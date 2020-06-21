#include<stdio.h>
#define sqrtt(x) (x)*(x)
int sqrtt1(int i){
    return i*i;
}
int main(){
    int i=3;
    int j=3;
    int c='a';
    FILE * f1=fopen("error_message.txt","r+");
    gets();
    printf("1:  %d   2:   %d",c,sqrtt1(++i));

//    fflush(stdout);
    fclose(f1);
    return 0;
}