#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>


void listDir(const char *path)
{
	DIR *dir = opendir(path);
	if (!dir) {
        	perror("opendir failed");
        	return;
    	}
	
	struct dirent *entry;
	struct stat info;
	char fullpath[1024];
	
	while ((entry = readdir(dir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
		continue;
		
		snprintf(fullpath, sizeof(fullpath) , "%s/%s", path, entry->d_name);
		
		if (stat(fullpath, &info) == 0) {
			if (S_ISDIR(info.st_mode)) {
				printf("[DIR ] %s\n", fullpath);
				listDir(fullpath);   // recursive call
			} 
			else if (S_ISREG(info.st_mode)) {
				printf("[FILE] %s\n", fullpath);
			}
        	}
	}
	
	closedir(dir);
	
}


int main()
{
	listDir(".");
    	return 0;
}
