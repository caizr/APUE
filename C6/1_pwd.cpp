#include<pwd.h>

int main(){
    struct passwd * p1=getpwuid(0);
    struct passwd * p2=getpwent();
    setpwent();
    struct passwd * p3=getpwent();
    endpwent();
    return 0;
}