#include<stdio.h>

int main(){
	char arr;
	FILE *fptr = fopen("dummy.txt", "r");
	FILE *fptr2 = fopen("dummy2.txt", "w");
	
	while(fscanf(fptr, "%c", &arr) != EOF){
		fprintf(fptr2, "%c", arr);
	}
	
	
}