#include<stdio.h>
#include<stdlib.h>

int main(){
	int num_of_elements = 0;
	int sum = 0;
	
	printf("Enter the number of Element to store in array: ");
	scanf("%d", &num_of_elements);
	
	int *arr = (int *)calloc(num_of_elements, sizeof(int));
	
	for(int i=0; i<num_of_elements;i++){
		printf("Enter Element %d: ", i+1);
		scanf("%d", arr + i);
		sum += *(arr + i);
	}
	
	printf("Total Sum is: %d", sum);
	
}