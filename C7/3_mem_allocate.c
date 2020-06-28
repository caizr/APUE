/* 存储空间分配
*
*  void *malloc(size_t size);                   分配size字节的空间, 里面的数据是随机
*  void *calloc(size_t nobj, size_t size);      为指定数量分配空间，即nobj*size字节，里面的数据都是0
*  void *realloc(void *ptr, size_t newsize);    改变原来分配区的长度，如果是增加空间，新增内容是不确定的
*  void free(void *ptr);                        释放空间
*/

#include<stdlib.h>
#include<stdio.h>

int main(){
    int *a = calloc(2,sizeof(int));
    a[0]=1;
    a[1]=2;
    free(a);
    return 0;
}