#include"../include/process_copy.h"

int block_cur(char* srcfile,int processnum){
	int fd;

	//打开文件
	fd = open(srcfile,O_RDWR);
	if(fd == -1){
		printf("%s\n",srcfile);
		perror("open srcfile2");
		exit(0);
	}

	//查看文件大小
	int filesize = 0;
	filesize = lseek(fd,0,SEEK_END);
	
	//给进程分配工作
	int blocksize = filesize / processnum + (filesize % processnum==0 ? 0 : 1);

	return blocksize;
}


