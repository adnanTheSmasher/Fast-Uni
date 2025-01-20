#include<stdio.h>

int main(){
	int rows, total_rows, k=0, n;
	printf("Enter upper rows number: ");
	scanf("%d", &rows);
	total_rows = (rows*2) +1;
	n = rows+1;
	
	
	for(int i=1;i<=total_rows;i++){
		(i<=n)?k++:k--;
		
		for(int j=1; j<=total_rows;j++){
			if(j>=n+1-k && j<=n-1+k)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}