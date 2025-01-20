#include<stdio.h>
#include<string.h>
int main(){
	int num;
	
	printf("Enter the number of words: ");
	scanf("%d", &num);
	
	char str[num][20];
	
		
	for(int i=0;i<num;i++){
		printf("Enter the word: ");
		scanf("%s", &str[i]);
	}
	
	for(int i=0;i<num;i++){
		int len = strlen(str[i]);
		strlwr(str[i]);
		char temp[len+1];
		int tempVar = 0;
		
		
		for(int j=len-1;j>=0;j--){
			temp[tempVar] = str[i][j];//
			tempVar++;
		}
		temp[len] = '\0';
	//	printf("%s", temp);
		
		if(strcmp(str[i], temp) == 0)
			printf("The string '%s' is Palindrome...", str[i]);
		else
			printf("The string '%s' is not Palindrome...", str[i]);
	}
	
	
	
	
	
}