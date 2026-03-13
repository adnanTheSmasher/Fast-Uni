#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
	pid_t pid1, pid2;
	
	pid1 = fork();
	
	if(pid1==0){
		printf("Child 1 PID: %d\n", getpid());
		exit(0);
	}
	
	pid2 = fork();
	
	if(pid2 == 0){
		printf("Child 2 PPID: %d\n", getppid());
		exit(0); 
	}
	
	wait(NULL);
	wait(NULL);
	
	printf("Parent Finished.\n");
	return 0;

}
