#include"../include/process_copy.h"
#include<sys/wait.h>

int process_wait(int blocksize)
{
		pid_t zpid; //返回子进程id
		int status; //输出参数  退出码或返回值
		int num = 0; //子进程完成任务的数量


		while((zpid = wait(&status)) > 0)
		{
			num++;
			printf("chlid %d NO.%d 结束工作",getpid(),num);
			sleep(5);
			if(num==blocksize){
				break;
			}
		}

		printf("%d个进程全部执行完毕\n",num);
}
