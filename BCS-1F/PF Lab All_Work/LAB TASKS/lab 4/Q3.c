/*
Create a calculator asking for operator (+ or – or * or /) and operands and
performs calculation according to the user input using switch statement.
*/

#include<stdio.h>
int main(){
	float num1, num2;
	char operator;
	
	printf("Enter number in this Format: num operator num\n");
	scanf("%f %c %f", &num1, &operator, &num2);
	
	switch(operator){
		case '+':
			printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
			break;
		case '-':
			printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
			break;
		case '*':
			printf("%.2f * %.2f = %.2f", num1, num2, num1 * num2);
			break;
		case '/':
			printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
			break;
		default:
			printf("invalid Format entered");
	}
	
}