#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isDouble, isManual;
    char coffeeType, askManual, askDouble;
    int time;

    printf("Welcome to the Coffee Shop\n");
    printf("Enter W for White coffee or B for Black coffee: ");
    scanf(" %c", &coffeeType); 

    printf("\nIs it Manual (Y/N): ");
    scanf(" %c", &askManual); 

    printf("\nIs it Double (Y/N): ");
    scanf(" %c", &askDouble); 

    switch (askManual) {
        case 'y':
        case 'Y':
            isManual = true;
            break;
        case 'n':
        case 'N':
            isManual = false;
            break;
        default:
            printf("\nInvalid Manual Input\n");
    }

    switch (askDouble) {
        case 'Y':
        case 'y':
            isDouble = true;
            break;
        case 'N':
        case 'n':
            isDouble = false;
            break;
        default:
            printf("\nInvalid Double Input\n");
    }

    printf("\n"); 

    switch (coffeeType) {
        case 'b':
        case 'B':
            time = 20 + 20 + 25 + 15 + 25; 

            if (isDouble) {
                time *= 1.5; 
            } 
            
            printf("Put Water - 20 min\n");
            printf("Put Sugar - 20 min\n");
            printf("Mix Well - 25 min\n");
            printf("Add Coffee - 15 min\n");
            printf("Mix Well - 25 min\n");
            printf("Total Time Will be: %d\n", time);
            break;

        case 'W':
        case 'w':
            time = 15 + 15 + 20 + 2 + 20; 

            if (isDouble) {
                time *= 1.5; 
            } 

            printf("Put Water - 15 min\n");
            printf("Put Sugar - 15 min\n");
            printf("Mix Well - 20 min\n");
            printf("Add Milk - 2 min\n");
            printf("Mix Well - 20 min\n");
            printf("Total Time Will be: %d\n", time);
            break;

        default:
            printf("\nInvalid Coffee Type\n");
    }

    return 0;
}