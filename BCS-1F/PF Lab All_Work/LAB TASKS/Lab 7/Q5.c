#include<stdio.h>
#include<string.h>
int main(){
	char strings[100];
	int length, isPalindrome = 0;

	printf("Enter your String: ");
	gets(strings);
	
	length = strlen(strings);
	//printf("%c",strings[length-1]);
	
	for(int i=0; i < length/2;i++){
		if(strings[i] == strings[length-i-1]){
			isPalindrome = 1;		
		}
	}

	if(isPalindrome)
		printf("The String \"%s\" is Palindrome....", strings);
	else
		printf("The String \"%s\" is not a Palindrome....", strings);

}