#include <stdio.h>

int main() {
    int arr[10], count, temp[10]; 

    for (int i = 0; i < 10; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        temp[i] = -1;
    }

    for (int i = 0; i < 10; i++) {
        count = 1; 
        if (temp[i] == -1) { 
            for (int k = i + 1; k < 10; k++) {
                if (arr[i] == arr[k]) {
                    count++;
                    temp[k] = 0; 
                }
            }
            temp[i] = count; 
        }
    }

    for (int i = 0; i < 10; i++) {
        if (temp[i] != 0) { 
            printf("The number %d occurs %d times.\n", arr[i], temp[i]);
        }
    }

    return 0;
}
