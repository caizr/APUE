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

    /***** 使用 mkdtemp(),mkstemp()  *****/
    // mkdtemp()创建临时目录
    // 使用char *d 的时候报错
    char d[]="/tmp/XXXXXX";
    char *dir_name=mkdtemp(d);      // d[]现在也会被改变
    printf("%s\n",dir_name);
    
    // mkstemp()创建临时文件
    // 使用char *e 的时候报错 
    char e[] = "fileXXXXXX";        // e[]同样会被改变
    mkstemp(e);
    printf("%s\n",e);
    return 0;
}