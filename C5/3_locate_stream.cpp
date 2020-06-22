/* 定位流
* long ftell(),int fseek(), void rewind()
*
*/
#include<iostream>

using namespace std;

int main(){
    FILE *f1 = fopen("3_text.txt","r+");
    // 写入一个字节
    putc(98,f1);
    // 偏移量为1
    cout<<ftell(f1)<<endl;
    
    /* ISO C标准的fgetpos(), fsetpos() */
    fpos_t p1;
    fgetpos(f1,&p1);
    //偏移量在__pos成员中
    cout<< p1.__pos<<endl;
    fsetpos(f1,&p1);
    return 0;
}