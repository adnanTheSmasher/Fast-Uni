/*
Write a C program to check whether a number is multiple of 3 or not. If it is
then print “This number is multiple of 3”, otherwise print “This number is not
multiple of 3”.
*/

#include<stdio.h>
int main(){
	int num;
	printf("Enter a number: ");
	scanf("%d", &num);
	if (num%3 == 0){
		printf("%d is a multiple of 3...", num);
	} 
	else {
		printf("%d is not a multiple of 3...", num);
	}
}
