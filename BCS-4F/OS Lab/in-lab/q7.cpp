#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
	pid_t pid = fork();
	
	if(pid==0){
		execlp("ls", "ls", "-l", NULL);
		perror("execlp Failed");
		exit(1);
		
	}else{
		wait(NULL);
		printf("CHILE finished exceution...\n");
	}
	return 0;
}
