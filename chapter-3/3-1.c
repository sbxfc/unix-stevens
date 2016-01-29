#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
//	if (open("create_file.test",O_CREAT) != -1){
//		printf("file created!/n");
//	}


	/*输出当前目录文件*/
	
//	execlp("ls","ls","-al",(char*)0);

	if(lseek(STDIN_FILENO,0,SEEK_CUR)==-1){
		printf("cannot seek\n");
	}	
	else{
		printf("seek OK\n");
	}
	
	exit(0);
}
