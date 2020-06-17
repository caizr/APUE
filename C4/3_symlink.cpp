/* 使用symlink()创建符号连接
*
*/
#include<iostream>
#include<unistd.h>

int main(){
    using namespace std;
    cout<<"symlink: "<<symlink("4_1.txt","sym4_1")<<endl;
    return 0;
}