#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
	printf("PID: %d\n", getpid());
	printf("PPID: %d\n", getppid());
	printf("UID: %d\n", getuid());
}
