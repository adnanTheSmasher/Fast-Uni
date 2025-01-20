#include<stdio.h>

#define MAX_TEMP 45.0


int temp_checker(float temp){
	static int counter = 0;
	
	if(temp > MAX_TEMP){
		counter++;
		printf("The temperature %.2f has exceeded the limit temperature of %.2f...", temp, MAX_TEMP);
	}
	else{
		printf("The temperature %.2f has not exceeded the limit temperature of %.2f...", temp, MAX_TEMP);
	}
	
	return counter;	
	
}

void counter_displayer(int counter){
	printf("The temperature exceeded the limit of %.2f %d time...", MAX_TEMP, counter);
}



int  main(){
	int counter; 
	char choice;
	float temp;
	
	
	do{
		printf("Enter Temperature: ");
		scanf("%f", &temp);
		
		counter = temp_checker(temp);
		
		printf("\nDo you want to continue (y/n): ");
		scanf(" %c", &choice);
	}while(choice == 'y' || choice == 'Y');
	
	counter_displayer(counter);
}