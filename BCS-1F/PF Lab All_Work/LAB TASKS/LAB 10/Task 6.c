#include<stdio.h>

int recursive_bubble(int arr[], int count){
	if(count == 1)
		return 0;
		
	else{
		for(int i=0;i<count-1;i++){
			if(arr[i] > arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	
	recursive_bubble(arr, count-1);
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1};
	
	recursive_bubble(arr, 9);
	
	for(int i=0;i<9;i++){
		printf("%d ", arr[i]);
	}
	
}