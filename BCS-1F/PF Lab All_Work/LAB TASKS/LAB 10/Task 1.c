#include<stdio.h>

int temp = 0;
int print_arr(int arr[], int size){
	if(size<=0){
		return 0;
	}
	
	else{
		temp++;
		printf("Element %d: %d\n", temp, arr[0]);
		print_arr(arr+1, size-1);
		
	}
}

int main(){
	int arr[5] = {1,2,3,5,5};
	print_arr(arr, 5);
}