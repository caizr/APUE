/* 二进制文件的读写
* size_t fread(); size_t fwrite();
*
*/

#include<iostream>
#include<string>
using namespace std;
struct Student{
    string name;
    int age;
    int score;
    Student(){};
    Student(string n,int a,int s): name(n),age(a),score(s){};
    ~Student(){
        cout<<"delete"<<endl;
    }
};
int main(){
  Student s1("petter",12,100);
   // 创建读取流
   FILE * f1=fopen("2_bin_files.txt","w+");
   // 输写入的字节数
  cout<<"write "<<fwrite(&s1,sizeof(s1),sizeof(s1),f1)<<" bytes"<<endl;
   // 创建新的读取流
   fflush(NULL);
   FILE * f2=fopen("2_bin_files.txt","r");
   Student *s2 = new Student{"a",0,0};
   // 输出读取的字节数
   cout<<"read "<<fread(s2,sizeof(s2),40,f2)<<" bytes"<<endl;
    cout<<s2->age<<endl;
    //fclose(f1);
  // fclose(f1);
   fclose(f2);
   return 0;
}