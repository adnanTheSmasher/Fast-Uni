#include<stdio.h>
#include<stdlib.h>


int largest_element(int arr[], int size){
	int largest = arr[0];
	for(int i=0; i<size; i++){
		if(arr[i] > largest){
			largest = arr[i];
		}
	}
	return largest;
}

int main(){
	int initial_size = 5;
	int arr[] = {2,5,6,7,8};
	int resize_num = 0;
	
	char choice;
	
	printf("Available Array = ");
	for(int i = 0;i<sizeof(arr)/sizeof(arr[0]);i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	
	printf("Resize the array or Find the largest(y to resize, n to find Largest): ");
	scanf("%c", &choice);
	
	if(choice == 'n'){
		printf("The largest element is: %d", largest_element(arr, initial_size));
	}
	else{
		int element_Size = 0;
		printf("Enter element size: ");
		scanf("%d", &element_Size);
		
		int *arr_pointer = (int *)calloc(element_Size, sizeof(int));
		
		for(int i=0; i<element_Size; i++){
			printf("Enter Element[%d]: ", i+1);
			scanf("%d", arr_pointer + i);
		}
		
		printf("The largest element is: %d", largest_element(arr_pointer, element_Size));
		
		
		
	}
	
}