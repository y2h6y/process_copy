#include"../include/process_copy.h"

int pram_check(int argc,char* srcfile,int processnum)
{
	if(argc != 4){
		printf("参数数量错误\n");
		exit(0);
	}
	if(0 != access(srcfile,F_OK)){
		printf("源文件不存在\n");
		exit(0);
	}
	if(processnum <= 3 || processnum > 80){
		printf("线程数不在会定范围内\n");
		exit(0);
	}
	return 1; 
}

