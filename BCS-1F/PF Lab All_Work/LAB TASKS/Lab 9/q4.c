#include<stdio.h>

int calculator(int num1,char sign,int num2){
	int result = 0;
	switch(sign){
		case '+':
			result = num1 + num2;
			break;	
		case '-':
			result = num1 - num2;
			break;	
		case '*':
			result = num1 * num2;
			break;	
		case '/':
			result = num1 / num2;		
			break;
		default:
			printf("Invalid Input....");
	}
	
	return result;
}

int main(){
	int num1,num2, result;
	char sign;
	
	
	printf("Write your Problem to perform calculation on 2 operands: ");
	scanf("%d %c %d", &num1, &sign, &num2);
	
	result = calculator(num1,sign,num2);
	
	printf("%d %c %d = %d", num1, sign, num2, result);
	
}
