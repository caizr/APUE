/* 时间
*   
*   time() 函数
%   clock_gettime()函数
*/
#include<time.h>        // time()
#include<sys/time.h>    // clock_gettime()
#include<iostream>


struct hello
{
    int a = 20;
};

using namespace std;
int main(){
    time_t time_second;
    /******************** time()  *********************/
    // time返回（如果参数是非空指针也往参数里写入）自1970-1-1-00:00:00历经的秒树
    time(&time_second);
    cout<<" time: "<<time(NULL)<<endl;
    cout<<" time_second: "<<time_second<<endl;


    /******************** clock_gettime()  *********************/
    // clock_gettime() 精度更高，支持纳秒级别的精度
    struct timespec t1,t2,t3;
    // CLOCK_REALTIME: 实时系统时间
    cout<<endl<<" clock_gettime of CLOCK_REALTIME: "<<clock_gettime(CLOCK_REALTIME, &t1)<<endl;
    cout<<" tv_sec: "<<t1.tv_sec<<endl;
    cout<<" tv_nsec: "<<t1.tv_nsec<<endl;

    // CLOCK_PROCESS_CPUTIME_ID: 调用进程的CPU时间
    cout<<endl<<" clock_gettime of CLOCK_REALTIME: "<<clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2)<<endl;
    cout<<" tv_sec: "<<t2.tv_sec<<endl;
    cout<<" tv_nsec: "<<t2.tv_nsec<<endl;

    // CLOCK_THREAD_CPUTIME_ID: 调用线程的CPU时间
    cout<<endl<<" clock_gettime of CLOCK_REALTIME: "<<clock_gettime(CLOCK_THREAD_CPUTIME_ID, &t3)<<endl;
    cout<<" tv_sec: "<<t3.tv_sec<<endl;
    cout<<" tv_nsec: "<<t3.tv_nsec<<endl;

    /******************** 将以上两种函数或得的秒级的时间转换为熟知的时间格式  *********************/
    struct tm *tm1 = new tm;
    // localtime 和gmtime区别就是考虑到本地地区和夏令时
    struct tm *tm2 =localtime(&time_second);
    tm1=gmtime(&time_second);
    cout<<endl<<1900+*(&tm1->tm_year)<<'-'<<*(&tm1->tm_mon)+1
        <<'-'<<*(&tm1->tm_mday)<<'-'
        <<*(&tm1->tm_hour)<<':'<<*(&tm1->tm_min)<<':'<<*(&tm1->tm_sec)<<endl;


    // 将tm结构转换为time_t秒级的时间结构
    time_t time_second2=mktime(tm1);
    cout<<"time_second2: "<<time_second2<<endl;


    // 打印 tm结构的时间格式 
    char buf_tm[100];
    int aa=strftime(buf_tm,100,"time: %c ",tm1);
    cout<< "write bytes(not include '\\0'): "<<aa<<endl
        <<buf_tm<<endl;
    return 0;
}