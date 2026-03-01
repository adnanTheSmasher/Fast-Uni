#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main()
{
    system("mkdir testdir");
    system("cp input.txt testdir/");
    system("ls");
    system("rmdir testdir");
    return 0;
	
}
