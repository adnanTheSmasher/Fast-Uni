#include<stdio.h>
int main(){
	int start, end, isPrime;
	
	printf("Enter the start and end number: ");
	scanf("%d %d", &start, &end);
	
	for(int i=start; i<=end;i++){
		if(i<2)
			continue;
			
		isPrime = 1;
		
		for(int j=2; j <= i/2;i++){
			if(i%j == 0)
				isPrime = 0;
				break;
	
		}
		
		if(isPrime)
			printf("%d is prime\n", i);
		
	}
	
}