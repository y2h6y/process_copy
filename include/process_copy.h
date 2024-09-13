#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<sys/types.h>

//参数检验  
int pram_check(int argc,char* srcfile,int processnum);
 
//任务分配    返回值：每个进程拷贝大小
int block_cur(char* srcfile,int processnum);

//进程创建
int process_create(char* srcfile,char* destfile,int blocksize,int processnum);

//回收进程
int process_wait(int blocksize);
