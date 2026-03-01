#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
	int fd1= open("input.txt", O_RDONLY);
	if (fd1 < 0){
		perror("Error opening input file");
		return 1;
	}
	
	int fd2 = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd2 < 0){
		perror("Error Opening Output File");
		close(fd1);
		return 1;
	}
	
	char buffer[1024];
	ssize_t bytes;
	
	while ((bytes = read(fd1, buffer, sizeof(buffer))) > 0) {
		if (write(fd2, buffer, bytes) != bytes) {
		    perror("Write error");
		    break;
		}
    	}
    	
    	close(fd1);
    	close(fd2);

}
