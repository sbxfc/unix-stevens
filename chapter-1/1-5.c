#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 4096

int main(void){
    
    char buf[MAXLINE];
	pid_t pid;
	int status;
	printf("%%");/*print prompt (print requires %% to print %)*/
    
    while(fgets(buf,MAXLINE,stdin) != NULL){
		
        /*execlp函数要求以null为结束符*/
        buf[strlen(buf)-1] = 0;/*replace newline with null*/
	

		if((pid = fork())<0){
			printf("fork error");
			exit(0);
		}
		else if(pid == 0 ){
            /*执行输入的命令*/
			execlp(buf,buf,(char*)0);
			printf("couldn't execute:%s",buf);
			exit(127);
		}
	
		/*parent*/
		if((pid = waitpid(pid,&status,0))<0){
			printf("waitpid error");
			exit(0);
		}
	
		printf("%%");
	}
}

