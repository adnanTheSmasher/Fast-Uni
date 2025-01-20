#include<stdio.h>

void swaped(int *aPtr, int *bPtr, int *cPtr){
	int temp;
	temp = *bPtr;
	*bPtr = *aPtr;
	*aPtr = *cPtr;
	*cPtr = temp;
}


int main(){
	int a = 10;
	int b = 20;
	int c = 30;
	
	int *aPtr = &a, *bPtr = &b, *cPtr = &c;
	
	printf("Before Swapping\n");
	printf("Value of A: %d\n", a);
	printf("Value of B: %d\n", b);
	printf("Value of C: %d\n", c);
	
	swaped(aPtr, bPtr, cPtr);
	
	printf("\nAfter Swapping\n");
	printf("Value of A: %d\n", a);
	printf("Value of B: %d\n", b);
	printf("Value of C: %d\n", c);
}