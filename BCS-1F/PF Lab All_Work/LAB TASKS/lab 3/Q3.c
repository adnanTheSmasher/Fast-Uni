//Question) A customer asks the IT firm to develop a program in C language, which can //take tax rate and salary from the user on runtime and then calculate the tax, the user //has to pay and the salary he/she will have after paying the tax. This information is then //provided to the user.

#include<stdio.h>
int main(){
	float tax_rate, salary;
	float total_salary, amount_of_tax;
	printf("Enter your salary: ");
	scanf("%f", &salary);
	printf("Enter your tax rate: ");
	scanf("%f", &tax_rate);
	amount_of_tax = (tax_rate/100) * salary; 
	total_salary = salary - amount_of_tax;	
	printf("Your total salary after cutting tax is: %.2f", amount_of_tax);
}
