#include<stdio.h>
#include<string.h>

char sorter(char str[][20],int size){
	char words[20];
	
	for(int i=0;i<size-1;i++){
		for(int j=0; j<size-1;j++){
			if(str[j][0] > str[j+1][0]){
				strcpy(words, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], words);
			}
		}
	}
	
	for(int i=0;i<size;i++){
		printf("%s\n", str[i]);
	}
	
	
}


int main(){
	char str[5][20] ={"HELLO","JELLO","MELLO","TELLO","BELLO"};
	
	sorter(str, 5);
	
}
