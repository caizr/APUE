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

            
    疑问 :   1. fwrite()之后再fread()出现segmention错误(2_cpp还是🈶
                这个问题)
chapter_5 NOTICE: 
            1. 标准I/O行缓冲的特点
            2. getc()为宏,fgetc()为函数, putc()和fputc()类似
            3. ftello(), fseeko()与没有o的区别就是偏移量的类型是off_t
