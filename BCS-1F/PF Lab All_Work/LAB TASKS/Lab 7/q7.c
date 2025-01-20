#include <stdio.h>

int main() {
    int isDuplicate, num, temp2 = 0; 

	printf("Enter the number of elements: ");
	scanf("%d", &num);
	int arr[num], temp[num];
	
    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
   for (int i = 0; i < num; i++) {
        int index = arr[i] % num; 
        if (arr[index] >= num) {
            printf("The number %d occurs more than once.\n", index);
            break;
        } else {
            arr[index] += num;
        }
    }
	

    return 0;
} 

