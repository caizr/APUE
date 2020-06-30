/* 通过getenv()函数获取特定的环境变量
*  通过putenv()或者setenv()设置
*/
#include<iostream>
#include<cstdlib>
#include<string>
int main(){
    /*********************getenv()获取环境变量*********************/
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

    /*********************putenv()获取环境变量*********************/
    putenv("TZA=test");
    std::cout<<"TZA: "<<getenv("TZA")<<std::endl;

    /*********************setenv(const char*,const char*, int)获取环境变量*********************/
    setenv("TZA","change",0);       // 0，如果环境变量存在，则不修改
    std::cout<<"TZA(setenv 0): "<<getenv("TZA")<<std::endl;
    setenv("TZA","change",1);       // 非0，如果环境变量存在，先删除原定义后再修改
    std::cout<<"TZA(setenv 1): "<<getenv("TZA")<<std::endl;

    /*********************unsetenv()获取环境变量*********************/
    std::cout<<"unsetenv(\"TZA\"): "<<unsetenv("TZA")<<std::endl;
    std::cout<<"unsetenv(\"TZB\"): "<<unsetenv("TZB")<<std::endl;
    return 0;
}