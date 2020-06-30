/* 通过getenv()函数获取特定的环境变量
*
*/
#include<iostream>
#include<cstdlib>
#include<string>
int main(){
    std::string s1="HOME";
    std::string s2="USER";
    // c_str()将string转换为const char *类型
    std::cout<<"HOME: "<<std::getenv(s1.c_str())<<std::endl
             <<"USER: "<<std::getenv(s2.c_str())<<std::endl
             <<"WHAT: "<<std::getenv("WHAT")<<std::endl;       //由于没有WHAT环境变量，故返回NULL

    std::cout.clear();      // 由于cout输出NULL,需要重置输出流
    std::cout<<"PWD: " <<std::getenv("PWD")<<std::endl;         //当前工作目录
    std::cout<<"PATH: " <<std::getenv("PATH")<<std::endl;         //当前工作目录
    fflush(stdout);
    return 0;
}