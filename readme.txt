学习 Advanced Programming in the UNIX Environment 3rd 的笔记
chapter_1:  open(),read(),write()[注意其中的O_APPEND追加模式];
            文件共享中文件的数据结构;原子操作; sync(),fsync()将
            缓存区数据写入磁盘(不保证一定写入磁盘); 
    疑问 :   FD_CLOEXEC是什么；使用fcntl(fd,F_SETFL,O_RDONLY)将O_RDWR
            设置成O_RDONLY，再次调用fcntl(fd,F_GETFL,0)还是O_RDWR
    习题 :   3.6
chapter_1 NOTICE: 
            1. 原子操作就是不能再细分的操作，比如先lseek后read，有
               可能lseek之后系统切换到另一个进程，如果另一个进程也
               操作同一个文件，那么再回到之前的进程之后read操作受影
               响了。pread为原子操作，不会中断其定位、读写操作
               open("filepath",O_CREAT|O_EXCL)组成原子操作
            2. fcntl(int fd,int cmd,...)
chapter_4:  stat(),lstat(),fstat,fstatat();acess()和faccessat()
            检查文件的权限;umask()屏蔽之后进程创建文件的部分权限;
            link(),linkat()函数; rename()函数;symlink()创建符号连接;
            chown(),fchown,fchownat(),lchown()没怎么看
            truncate(),ftruncate()截断文件; mkdir(), rmdir()创建
            以及删除文件夹; 4.22实例-降序遍历文件夹没有看; chdir()切
            换当前进程的工作目录; getcwd()获取当前工作目录的绝对路径
            4.24跳过
            
    疑问 :   使用6_umask.cpp中使用creat()创建文件,组和其他都没有写权限 
            应该是与umask有关，在终端输入umask就可以发现程序的umask会
            影响到全局
chapter_4 NOTICE: 
            1. stat()不能检测符号连接，lstat()可以检测；
            2. S_ISxxx()宏
            3. 文件夹具有执行权限的意义：
                a. 为了打开 /usr/include/stdio.h, 目录/, /usr以及
                   /usr/include需要具备执行权限！！！
                b. 目录的执行权限使得我们能够搜索目录
                c. 为了在目录中创建文件，目录除了具备写权限之外，还应该
                   具备执行权限！！！
                d. 为了删除一个现有文件，包含该文件的目录除了写权限之外,
                   还应该具备执行权限！！！
            4. 使用chmod修改某个文件的权限时，如果直接执行以下语句：
                     chmod("6_3.txt",S_IRGRP|S_IWGRP);
               会造成用户和其他的权限位为空，所以最好使用stat结构体里面
               的st_mode进行或运算
            5. 使用link函数只是建立一个连接，这几个文件指向的是磁盘的同
               一内容，也就是说，当前文件夹如果有1个文件，多个此文件连接
               的话，该文件夹的占用空间仍然只有这1个文件的大小，仔细体会。
            6. rename()函数分为好几种情况(newpath为目录、符号连接，或者
                已经存在该文件/目录等)
            7. mkdir()的mode参数为S_IRWXU那一类
            8. 使用OPEN打开一个符号连接文件的时候，OPEN实际上是在操作符号
               连接指向的那个文件。如果要对符号连接本身进行处理，需要用
               readlink()函数

chapter_5:  setbuf(),setvbuf()修改流的缓存类型;fflush()强制冲洗流；
            fopen(),freopen(),fdopen打开流; fclose()关闭流; 
            ferror(),feof()返回流的状态信息（出错还是到达末尾），
            clearerr()清除状态信息；
            getc(),fgetc(),getchar()以及putc(),fputc,putchar();
            fread(),fwrite()读写二进制文件;
            ftell(),fseek(),ftello(),fseeko()文件偏移；
            fgetpos(),fsetpos()适用于跨平台，偏移量超出off_t范围，所以
            更通用
            printf(),fprintf(),dprintf(),sprintf(),snprintf();格式
            化控制输出
            同理scanf()函数族
            mkdtemp()创建临时目录,mkstemp()创建临时文件
            内存流没有看，跳过

            
    疑问 :   1. fwrite()之后再fread()出现segmention错误(2_cpp还是🈶
                这个问题)
chapter_5 NOTICE: 
            1. 标准I/O行缓冲的特点
            2. getc()为宏,fgetc()为函数, putc()和fputc()类似
            3. ftello(), fseeko()与没有o的区别就是偏移量的类型是off_t
            4. 对于mkdtemp(),mkstemp(), 参数应该是char[] 而不是char *，
               因为char * 指向的是常量区, 修改这个区域会出现seg error
            5. mkdtemp()和mkstemp()创建的临时目录和文件不会被删除


chapter_6:  pwd.h中的passwd结构; getpuid(),getpwnam()获取passwd结构;
            getpwent(),setpwent(),endpwent()按顺序查看所有口令； 阴影
            口令；系统标识 utsname结构, gethostname()函数; time()函数和
            clock_gettime()函数获取时间; tm结构，gmtime()，localtime()
            函数将秒级精度的时间转换为熟悉的时间结构，strftime()将tm结构打印
            出设定的格式, strptime()即将字符串转换为tm时间结构
            
    疑问 :   1. 
chapter_6 NOTICE: 
            1. getpwent()从uid=0开始访问用户，访问结束需要使用endpwent()
               关闭文件否则下次getpwent()不是从头开始。使用setpwent()可以
               重置，是getpwent()从0开始。
            

chapter_7:  进程环境。exit(),_Exit(),_exit()函数用于正常终止一个程序；
            atexit()在exit时添加一些要执行的函数； argc命令行参数; 
            environ环境变量; gxx -static 编译; malloc(size_t), 
            calloc(size_t,size_t),re_Exit(),_exit()函数用于正常终止一个程序；
            atexit()在exit时添加一些要执行的函数； argc命令行参putenv(),setenv(),unsetenv()获取、
            修改、删除某个环境变量
            
    疑问 :   
            1. setjump, longjump跳转没有看
            2. 资源限制没有看 
chapter_7 NOTICE: 
            1. return 0与exit(0) 作用是一样的（main函数中），都会退出程序
               （并关闭一些已经
               打开的流等清理操作）。
            2. 了解c程序是如何启动的，以及它终止的各种方式（图7-2），注意，在
               某个函数中调用exit()或导致整个程序都退出!所以刚才第一点说的return
               和exit作用一样的前提是在main函数执行。
            3. atexit()装填顺序与调用顺序是相反的
            4. 环境表需要声明： extern char **environ或者在main()的第三个参数
               main(int argc, char **argv, char **envp),但是不推荐使用这个。
            5. gcc/g++ -static 编译的时候，将任何依赖的函数包含进去，所以编译出来
               的文件会很大，但是编译出来的程序不依赖任何库
            6. malloc()分配的空间内的数据是随即,calloc()全部清0
            7. 不要用putenv(), 因为putenv的参数不会开辟的新的空间来存放这个字符串，
               所以如果这个字符串假如在栈里面，很容易出问题（比如栈空间释放），参考
               图7-6

chapter_8:  getpid(),getppid()等获取标识符
            fork()创建子进程；vfork()保证子进程先执行（exec或者exit之后父进程才会
            接着运行）, wait(),waitpid(),waitid()获取子进程的信息
            竞争的定义，原因；轮询；
            exec()函数族
            更改用户ID和组ID没有看
            解释器文件跳过，应该就是脚本文件，exec()可以运行脚本文件
            system()函数执行命令
            进程会计，用户标识，进程调度，进程时间没看
            
    疑问 :   
            1. s
chapter_8 NOTICE: 
            1. pid: 进程ID，ppid：父进程id；uid：实际用户ID； gid： 组ID
            2. fork()创建子进程，fork()返回两次函数值，子进程0，父进程为子
               进程的ID。进程后面的语句都会被调用。
            3. fork()子进程内的变量和父进程的不会相互影响。
            4. fork()子进程和父进程共享文件描述符（不是共用同一块存储位置，而是
               复制）
            5. fork()子进程的变量会影响父进程中的变量，但是文件描述符仍然是副本
            6. 如果父进程终止，子进程还没终止，会变成孤儿进程，现在他的父进程ID
               是init(PID为1)； 如果子进程终止，父进程没有合理的处理终止的子进程，
               那么子进程会变成僵尸进程，直到父进程结束该僵尸进程被init进程托管，
               init进程会自动处理僵尸进程
            7. 子进程终止后，父进程需要对其妥善处理（释放资源等），否则会变成僵死
               进程
            8. 轮询： 
               while( getppid()!= 1){
                  sleep(1);
               }
               以上代码为子进程等待父进程终止（因为父进程终止则当前的子进程的父进程
               会变成init进程), 该形式为轮询, 轮询浪费时间
            9. 4_race.c 中可能会看到output from opuatrpeuntt  fr
               om child  这样的输出，我一开始使用c++中的cout是看不到的， setbuf把
               标准输出流的缓存关闭，使其尽可能的看到竞争条件的发生
               为了使子进程运行时初始化并通知父进程，并且父进程也对该通知进行处理之后再
               通知子进程，子进程收到通知之后才运行后面的语段，父进程也在完成通知之后运行
               后面的语段
            10. 使用exec函数族的时候，如果是char *arg[]的参数，其数组最后一个也应该是
                NULL指针
chapter_10:  signal函数,sigaction函数 https://blog.csdn.net/weibo1230123/article/details/81411827
            没看： 10.11 10.12 10.13


chapter_11:  线程, pthread_self()函数，pthread_creat()函数，pthread_exit()， pthread_join()
                  pthread_cleanup_push()和pthread_cleanup_pop()这一对函数
            没看： 10.11 10.12 10.13
chapter_11 NOTICE: 
            1. pthread_cread()创建的线程不能保证马上就会产生新线程，所以返回的值放在主程序打印的话，打印出的值不是
               正确的线程ID！可以在该函数的start_rtn参数中通过pthread_self()获取线程ID并打印出
            2. 线程调用exit会导致整个进程的终止
            3. 在线程中创建的栈内的变量空间，退出线程后，该空间的内容可能会改变
            4. pthread_cleanup_push()和pthread_cleanup_pop()一定要配对使用，不然会报错 (while '}'这样的错误 )
            5. 书上说pthread_clearn在pthread_exit()的情况下才会调用，return()不会调用，但我在ubuntu 20.04的系统
               下return仍然会调用pthread_clearn中的清理函数