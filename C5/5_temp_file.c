#include<stdio.h>
#include<stdlib.h>
int main(){
    char *b =(char *)malloc(20);
    char *c = (char *)malloc(20);
    // 使用tmpnam()产生临时文件名
    tmpnam(b);
    printf("%s \n",b);
    c=tmpnam(b);
    printf("%s\n",c);

    // 使用 mkdtemp(),mkstemp()
    char *d="filexxxxxx";
    d=mkdtemp(d);
    printf("%s\n",d);
    return 0;
}