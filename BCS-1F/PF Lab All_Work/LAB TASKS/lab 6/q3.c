#include<stdio.h>
int main(){
	int num, isPrime=1, num1=0, num2=1, sum = 0;
	
	printf("Enter any number: ");
	scanf("%d", &num);
	
	for (int i=2; i<num; i++){
		if(num%i==0)
			isPrime = 0;
	}
	if (isPrime)
		printf("Number is Prime...\n");
	else
		printf("Number is not Prime...\n");
	
	for(int i=1; i<=num; i++){
		printf("%d ", num1);
		sum = num1+num2;
		num1 = num2;
		num2 = sum;
	}
}
