#include<stdio.h>
int main(){
	int rows = 5,num = 1;
	
	for(int i=0; i<5; i++){
		for(int k=1; k<=rows-i; k++)
			printf(" ");
			
		for(int j=0;j<=i;j++){
			if(j==0 || i==0)
				num = 1;
			else
				num = num*(i-j+1)/j;
			printf("%d ", num);
		}
		printf("\n");
	}
}