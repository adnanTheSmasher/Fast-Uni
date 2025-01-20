#include<stdio.h>

void swapIntegers(int *num1,int *num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main(){
	int num1,num2;
	
	printf("Enter 2 numbers you want to swap with spaces: ");
	scanf("%d %d", &num1, &num2);
	
	printf("\nBefore Swapping Values %d | %d.", num1,num2);
	swapIntegers(&num1, &num2);
	printf("\nAfter Swapping Values %d | %d.", num1,num2);	
}

