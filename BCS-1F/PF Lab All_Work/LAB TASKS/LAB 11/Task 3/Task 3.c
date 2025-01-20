#include <stdio.h>
#include <string.h>

void search_And_Replace(char *fname, char *oldWord[100], char *newWord[100]){
	FILE *fptr = fopen(fname, "r");
	FILE *temp = fopen("temp.txt", "w");
	char line[256];	
	
	while(fgets(line, sizeof(line), fptr)){
		char *pos = line;
		
		while((pos = strstr(pos, oldWord)) != NULL){
			fwrite(line, 1, pos-line, temp);
			fputs(newWord, temp);
			pos += strlen(oldWord);
			strcpy(line, pos);
			pos = line;
		}
		fputs(line, temp);
	}
	
	fclose(fptr);
	fclose(temp);
	
	remove(fname);
	rename("temp.txt", fname);
	
	
	
	
}


int main(){
	char oldWord[] = "Adnan";
	char newWord[] = "Hussain";
	char fname[] = "text.txt";
	search_And_Replace(fname, &oldWord, &newWord);
}