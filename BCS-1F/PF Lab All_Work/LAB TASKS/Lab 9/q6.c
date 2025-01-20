#include<stdio.h>
#include<string.h>

int max_min_finder(int arr[], int size,int *min,int *max){
	
	for(int i=0;i<size;i++){
		if(arr[i] > *max)
			*max = arr[i];
		else if(arr[i] < *min){
			*min = arr[i];
		}
	}
	
	
}


int main(){
	int len, min = 99999, max=-99999;
	printf("Enter the number of Elements: ");
	scanf("%d", &len);
	int arr[len];
	
	for(int i=0;i<len;i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	max_min_finder(arr, len, &min, &max);
	printf("Maximin: %d\n", max);
	printf("Minimum: %d", min);
	
}
