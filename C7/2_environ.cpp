/* 环境变量
*   extern char **environ 环境表，类似char **argv
*
*/

#include<iostream>
#include<iterator>
extern char ** environ;
int main(int argc, char **argv){
    using namespace std;

    // 自己的方法
    for(char **c=environ;*c!=NULL;++c){
        cout<<*c<<endl;
    }
    cout<<endl<<endl;
    // 书上的方法
    for(int i=0;environ[i]!=NULL;++i){
        cout<<environ[i]<<endl;
    }
    return 0;
}