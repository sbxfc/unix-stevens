#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void){
	int fd;
	if((fd = creat("file.hole",O_CREAT))<0){
		printf("creat error");
		exit(0);
	}

	
	if(write(fd,buf1,10)!=10){
		printf("buf1 write error");
		exit(0);
	}

	/*offset now = 10 */

	if(lseek(fd,40,SEEK_SET) == -1){
		printf("lseek error");
		exit(0);
	}
	/*offset now = 40 */

	if(write(fd,buf2,10)!=10){
		printf("buf2 write error");
		exit(0);
	}

	/*offset now = 50 */
	exit(0);
}
