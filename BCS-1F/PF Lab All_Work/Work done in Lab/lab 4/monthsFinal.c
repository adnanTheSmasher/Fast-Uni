#include<stdio.h>
int main(){
	char month_name;
	int num;
	printf("Enter first letter of month: ");
	scanf("%c", &month_name);
	printf("Enter Number: ");
	scanf("%d", &num);
	
	switch(month_name){
		case 'A':
		case 'a':{
			switch(num){
				case 0:
					printf("April");
					break;
				case 1:
					printf("August");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'J':
		case 'j':{
			switch(num){
				case 0:
					printf("January");
					break;
				case 1:
					printf("June");
					break;
				case 2:
					printf("July");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'F':
		case 'f':{
			switch(num){
				case 0:
					printf("Febuary");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'M':
		case 'm':{
			switch(num){
				case 0:
					printf("March");
					break;
				case 1:
					printf("May");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'S':
		case 's':{
			switch(num){
				case 0:
					printf("September");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'O':
		case 'o':{
			switch(num){
				case 0:
					printf("October");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'N':
		case 'n':{
			switch(num){
				case 0:
					printf("November");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		case 'D':
		case 'd':{
			switch(num){
				case 0:
					printf("December");
					break;
				default:
					printf("Invalid number of month....");
			}
			break;
		} break;
		default:
			printf("Default running");
	}
	
}
