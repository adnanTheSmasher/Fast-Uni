#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


void handler(int sig) {
    printf("\nAlarm received. Exiting...\n");
    exit(0);
}

int main()
{
	signal(SIGALRM, handler);
	alarm(5);
	
	while(1){
		printf("Running....\n");
		sleep(1);
	}	
	return 0;
}
