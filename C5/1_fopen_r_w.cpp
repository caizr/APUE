#include<iostream>

/*  
*  int getc(FILE * fp), int fgetc(FIIE *fp)
*  int ungetc(int c, FILE *fp)
*/
int main(){
    using namespace std;
    FILE * f1=fopen("error_message.txt","r+");
    cout<< fgetc(f1)<<getc(f1)<<getc(f1)<<getc(f1);
    fputc(99,f1); 
    return 0;
}