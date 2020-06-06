/* 检查文件的访问权限

*/
#include<iostream>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char ** argv){
    using namespace std;
    struct stat buf;
    // 检测是否调用错误
    if(argc <2 ){
        cout<<"usage error!"<<endl;
        return -1;
    }

    for(int i=1;i<argc;++i){
        cout<<argv[i]<<" :";
        //read test
        if(access(argv[i],R_OK)<0)
            cout<<"read error!"<<" ";
        else
            cout<<"read sucess!"<<" ";
        // 测试该文件是否能打开？
        if(open(argv[i],O_RDONLY)<0){
            cout<<"open "<<argv[i]<<" error!"<<endl;
            continue;
        }
        //wriet test
        if(access(argv[i],W_OK)<0)
            cout<<"write error!"<<" ";
        //execute test
        if(access(argv[i],X_OK)<0)
            cout<<"execute error!"<<" ";
        cout<<endl;
    }

}