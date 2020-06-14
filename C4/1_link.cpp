/* 使用link创建链接
*/
#include<iostream>
#include<unistd.h>

int main(){
    using namespace std;
    //创建符号连接
    cout<<"link: "<<link("4_1.txt","link4_1.txt")<<endl;
    //删除符号连接
    //cout<<"unlink: "<<unlink("4_1.txt")<<endl;
    return 0;
}