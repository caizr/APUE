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
chapter_4:  stat(),lstat(),fstat,fstatat();
chapter_1 NOTICE: 
            1. stat()不能检测符号连接，lstat()可以检测；
            2. S_ISxxx宏
            3.  ceshi 
            