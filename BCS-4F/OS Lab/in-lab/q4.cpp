#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
	        printf("Usage: ./stat 1$2$3$4\n");
	        return 1;
    	}
    	
    	int arr[100], n = 0;
    	char *token = strtok(argv[1], "$");
    	
    	while(token!=NULL){
		arr[n++] = atoi(token);
		token = strtok(NULL, "$");
	}
	
	pid_t pid1 = fork();
	
	if(pid1 == 0){
		int sum = 0;
		for(int i=0; i<n;i++)
			sum += arr[i];
		printf("Sum: %d\n", sum);
		exit(0);
	}
	
	pid_t pid2 = fork();

	if (pid2 == 0) {
		int sum = 0;
		for (int i = 0; i < n; i++)
		    sum += arr[i];
		printf("Average: %.2f\n", (float)sum / n);
		exit(0);
	}

	pid_t pid3 = fork();

	if (pid3 == 0) {
		int max = arr[0];
		for (int i = 1; i < n; i++)
		    if (arr[i] > max) max = arr[i];
		printf("Max: %d\n", max);
		exit(0);
	}

	wait(NULL);
	wait(NULL);
	wait(NULL);

	return 0;

}
