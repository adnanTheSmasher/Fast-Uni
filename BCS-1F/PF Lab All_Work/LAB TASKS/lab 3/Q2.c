//Question) Write a C program that takes two integer values as input from the user. //Then swap the values taken from the user and display the output of the variables.

#include<stdio.h>
int main(){
	int num1, num2, temp;
	printf("Enter number 1: ");
	scanf("%d",&num1);
	printf("Enter number 2: ");
	scanf("%d",&num2);
	temp = num1;
	num1 = num2;
	num2 = temp;
	printf("Value of Number 1 after SWAPPING: %d\n", num1); 
	printf("Value of Number 2 after SWAPPING: %d", num2);
}
