#include <stdio.h>

int main() {
    int calories, fat_grams;
    float calories_from_fat, percentage;

    printf("Enter the number of calories: ");
    scanf("%d", &calories);

    printf("Enter the number of fat grams: ");
    scanf("%d", &fat_grams);

    if (calories < 0 || fat_grams < 0) {
        printf("Error: Calories and fat grams cannot be less than 0.\n");
        return 1;
    }

    calories_from_fat = fat_grams * 9;

    if (calories_from_fat > calories) {
        printf("Error: Calories from fat cannot be greater than total calories.\n");
        return 1;
    }

    percentage = (calories_from_fat / calories) * 100;

    printf("The total calories are: %.2f%%\n", percentage);

    return 0;
}