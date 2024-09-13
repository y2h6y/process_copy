#include<process_copy.h>

int process_create(char* srcfile,char* destfile,int blocksize,int processnum){
	int pos = 0;  //拷贝起始位置
	int i = 0;
	pid_t pid;

	//创建子线程
	for(i=0;i<processnum;i++){
		pid = fork();
		if(pid == 0){
			pos = blocksize*i;
			break;
		}
	}

	if(pid == 0){
		//打开并读写原文件和目标文件
		int fd = 0;
		int destfd = 0;
		char buffer[4096]= {};
		memset(buffer,0,4096);
		
		fd = open(srcfile,O_RDWR);
		if(fd == -1){
			perror("open srcfile1");
			exit(0);
		}

		destfd = open(destfile,O_RDWR);
		if(destfd == -1){
			perror("open destfile");
			exit(0);
		}

		//将源文件光标移动到未读位置
		lseek(fd,i*blocksize,SEEK_SET);
		lseek(destfd,i*blocksize,SEEK_SET);
		//读操作
		int readlen = read(fd,buffer,blocksize);
		//写操作

		printf("%d  %s\n",readlen,buffer);
		write(destfd,buffer,blocksize);
		return 0;
	}
	else{
		process_wait(blocksize);
	}
}
