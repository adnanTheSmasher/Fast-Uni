#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
	printf("Original Process PID: %d\n", getpid());

	pid_t pid = fork();

	if (pid == 0) {
		printf("CHILD process\n");
		printf("My PID: %d\n", getpid());
		printf("My Parent PID: %d\n", getppid());
	}
	else if (pid > 0) {
		printf("PARENT process\n");
		printf("My PID: %d\n", getpid());
		printf("My Child PID: %d\n", pid);
		wait(NULL);
	}
	return 0;
}
