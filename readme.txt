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
<<<<<<< HEAD
            link(),linkat()函数; rename()函数; 
=======
            chown(),fchown,fchownat(),lchown()没怎么看
            truncate(),ftruncate()截断文件;
>>>>>>> b0a0055c982d294c320f20f048fbb74390a7cd3b
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