#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char name[100];
	char id[20];
	int number_of_characters;
	
	printf("Enter the number of character in your name(first + Last): ");
	scanf("%d", &number_of_characters);
	printf("Enter your name: ");
	getchar();
	gets(name);
	
	char *arr = (char *)calloc(number_of_characters + 1, sizeof(char));
	
	strcpy(arr, name);
	
	printf("\nDynamic Array Before Appending: '%s'\n\n", arr);
	printf("Enter your Student ID (24k-XXXX): ");
	gets(id);
	
	int size = strlen(arr) + strlen(id) + 2;
	
	int *id_pointer = (char *)realloc(arr, size * sizeof(char));
	arr = id_pointer;
	
	
	strcpy(arr, id);
	strcat(arr, " ");
	strcat(arr, name);
	printf("\nDynamic Array after Appending: '%s'\n", arr);
	free(arr);
	free(id_pointer);
}