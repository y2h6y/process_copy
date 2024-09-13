#include<process_copy.h>

int main(int argc,char** argv)
{
	printf("%s\n%s\n%s\n%s\n",argv[0],argv[1],argv[2],argv[3]);

	//将字符串转为int值
	int processnum = atoi(argv[3]);

	//参数检验
	pram_check(argc,argv[1],processnum);
	
	//分配
	int blocksize = block_cur(argv[1],processnum);

	//创建线程
	process_create(argv[1],argv[2],blocksize,processnum);

	return 0;
}

