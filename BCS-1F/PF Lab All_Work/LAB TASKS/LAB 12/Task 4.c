#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char name[100];
	int number_of_characters;
	
	printf("Enter the number of character in your name(first + Last): ");
	scanf("%d", &number_of_characters);
	printf("Enter your name: ");
	getchar();
	gets(name);
	
	char *arr = (char *)calloc(number_of_characters + 1, sizeof(char));
	
	strcpy(arr, name);
	
	printf("Dynamic Array: '%s'", arr);
	
	free(arr);
	
}