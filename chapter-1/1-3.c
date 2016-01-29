#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc,char *argv[]){
	
	DIR *dp;
	struct dirent *dirp;
	if(argc != 2)
	{		
		printf("Not a directory!\n");
		exit(0);	
	}	
	/*opendir返回DIR结构的指针*/
	if((dp=opendir(argv[1])) == NULL){
		printf("can't open %s\n",argv[1]);
		exit(0);
	}
	
	/*readdir读每个目录*/
	while((dirp = readdir(dp)) != NULL){
		printf("%s \n",dirp->d_name);
	}

	closedir(dp);
	exit(0);
}
