#include<stdio.h>
#include<string.h>

char reversal(char str[], int size){
	char temp[size];
	int length = strlen(str);
	int tempVar = 0;
	for(int i=length-1;i>0;i++){
		temp[tempVar] = str[i];
		tempVar++;
	}
	temp[length] = '\0';
	
	return *temp;
}


int main(){
	char str[20], result[20];
	
	printf("Enter the string: ");
	fgets(str, 20, stdin);
	
	result = reversal(str, 20);
	printf("%s", result);
	
	
}
