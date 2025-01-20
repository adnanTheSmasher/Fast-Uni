#include <stdio.h>

int linearSearch(int arr[], int size, int target, int index){
	if(index >= size){
		return 1;
	}
	
	else{
		if(arr[index]==target){
			return index;
		}
		
		linearSearch(arr, size, target, index+1);
	}
}


int main(){
	int arr[] = {5, 3, 8, 4, 2, 1, 9};
	int target, index;
	
	printf("Enter the target Element: ");
	scanf("%d", &target);
	
	printf("Enter the index to start searching: ");
	scanf("%d", &index);
	
	int result = linearSearch(arr, 7, target, index);
	
	if (result == 1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
	
}