#include <stdio.h>

int main(){
	int arr[6], temp[6], temp_var = 6;
	for(int i=1;i<=6;i++){
		printf("Enter number %d: ", i);
		scanf("%d", &arr[i]);		
	}
	for(int i=1;i<=6;i++){
		if(i == 1)
			temp[i] = arr[temp_var];
		else
			temp[i] = arr[i-1];		
	}
	for(int i=1;i<=6;i++){
		printf("\nnumber %d: %d", i,temp[i]);		
	}
	
}
