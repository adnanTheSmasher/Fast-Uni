#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESTINATION_LENGTH 50

struct TravelPackage {
    char package_name[MAX_NAME_LENGTH];
    char destination[MAX_DESTINATION_LENGTH];
    int duration; 
    float cost;   
    int seats_available; 
};


void display_packages(struct TravelPackage packages[], int count) {
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < count; i++) {
        printf("Package %d:\n", i + 1);
        printf("  Name: %s\n", packages[i].package_name);
        printf("  Destination: %s\n", packages[i].destination);
        printf("  Duration: %d days\n", packages[i].duration);
        printf("  Cost: $%.2f\n", packages[i].cost);
        printf("  Seats Available: %d\n", packages[i].seats_available);
        printf("-----------------------------------\n");
    }
}


void book_package(struct TravelPackage packages[], int count) {
    int package_number;
    printf("Enter the package number you want to book: ");
    scanf("%d", &package_number);

    if (package_number < 1 || package_number > count) {
        printf("Invalid package number. Please try again.\n");
        return;
    }

    package_number--;

    if (packages[package_number].seats_available > 0) {
        packages[package_number].seats_available--;
        printf("You have successfully booked the package: %s\n", packages[package_number].package_name);
        printf("Seats remaining: %d\n", packages[package_number].seats_available);
    } else {
        printf("Sorry, no seats available for the package: %s\n", packages[package_number].package_name);
    }
}

int main() {
    struct TravelPackage packages[MAX_PACKAGES];
    int count = 0;
    char choice;

    strcpy(packages[count].package_name, "London Tour");
    strcpy(packages[count].destination, "London");
    packages[count].duration = 7;
    packages[count].cost = 1499.99;
    packages[count].seats_available = 5;
    count++;

    strcpy(packages[count].package_name, "World Tour");
    strcpy(packages[count].destination, "100 countries");
    packages[count].duration = 50;
    packages[count].cost = 50000.99;
    packages[count].seats_available = 3;
    count++;

    strcpy(packages[count].package_name, "City Exploration");
    strcpy(packages[count].destination, "New York");
    packages[count].duration = 4;
    packages[count].cost = 599.99;
    packages[count].seats_available = 10;
    count++;

    do {
        printf("\nTravel Package Booking System\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                display_packages(packages, count);
                break;
            case '2':
                book_package(packages, count);
                break;
            case '3':
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '3');

    return 0;
}