#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Words{
	char words[100];
	int wordCount;
};


int main(){
	struct Words words[10]; // file contains 10 words
	FILE *fptr = fopen("text.txt", "r");
	char word[100];
	int totalWords = 0;
	
	while(fscanf(fptr, "%s", word) == 1){
		for(int i=0; word[i] != '\0'; i++){
			word[i] = tolower(word[i]);
		}
		
		int found = 0;
		for(int i=0; i<totalWords; i++){
			if(strcmp(words[i].words, word) == 0){
				words[i].wordCount++;
				found = 1;		
			}
		}
		
		if(!found){
			strcpy(words[totalWords].words, word);
			words[totalWords].wordCount = 1;
            totalWords++;
		}
	}
	
	fclose(fptr);
	for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i].words, words[i].wordCount);
    }
	
}