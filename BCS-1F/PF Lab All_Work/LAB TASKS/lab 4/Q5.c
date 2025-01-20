#include<stdio.h>

int main(){
	char letter;
	printf("Enter any Character: ");
	scanf("%c", &letter);
	if(letter >= 'a' && letter <= 'z'){
		printf("%c is a small letter...", letter);
	} else if(letter >= 'A' && letter <= 'Z'){
		printf("%c is Capital letter...", letter);
	} else if(letter >= '0' && letter <= '9'){
		printf("%c is a Digit...", letter);
	} else {
		printf("%c is a special character", letter);
	}
	
}