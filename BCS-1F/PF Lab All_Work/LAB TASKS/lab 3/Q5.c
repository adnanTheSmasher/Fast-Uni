#include<stdio.h>
int main(){
	float principal, interest_rate, time, total;
	printf("Enter amount of principal (between 100 Rs-1,000,000 Rs): ");
	scanf("%f", &principal);
	
	if (principal >= 100 && principal <= 1000000){
		printf("Enter amount of Interest (between '5%' - '10%'): ");
		scanf("%f", &interest_rate);
		if (interest_rate >= 5 && interest_rate <= 10){
				printf("Enter amount of Time (between 1 year- 10 year): ");
				scanf("%f", &time);
				if (time >= 1 && time <= 10){
					total = principal * (interest_rate/100) * time;
			} else 
					printf("Invalid Input Entered. Try Again....");
		} else
			printf("Invalid Input Entered. Try Again...."); 
}	else
		printf("Invalid Input Entered. Try Again...."); 
	
	printf("Your total is: %.2f", total);
}
