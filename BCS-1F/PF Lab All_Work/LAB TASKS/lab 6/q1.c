/*
Answer:
	Using do-while loop would be better for taking user input  as it allows user a choice if user wants to comtinue or not if not it will exit or else it will continue.
	from the given example it could be seen that using do-while loop is much more efficient and effective when taking user inputs atleast 1 time
*/
#include<stdio.h>
int main(){
	int num, sum;
	do{
		printf("Enter any number (0 to quit): ");
		scanf("%d",&num);
		if (num!=0){
			sum += num;
			printf("Current Sum: %d\n", sum);
		}
	}while(num!=0);
	
	printf("Sum: %d", sum);
}
