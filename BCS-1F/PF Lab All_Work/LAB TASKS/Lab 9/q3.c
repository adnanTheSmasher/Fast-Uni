#include<stdio.h>

int PrimeChecker(int num){
	int isPrime = 0;
	for(int i=2;i<num;i++){
		if(num%i==0){
			isPrime = 1;
			break;
		}
		else
			isPrime = 0;
	}
	return isPrime;
	
}

int main(){
	int num;
	
	printf("Enter Any number to check Prime or No Prime: ");
	scanf("%d", &num);
	
	if(PrimeChecker(num))
		printf("The number %d is not Prime....", num);
	else
		printf("The number %d is Prime....", num);
}