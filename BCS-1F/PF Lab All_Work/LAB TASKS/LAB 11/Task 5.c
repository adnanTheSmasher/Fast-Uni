#include <stdio.h>
#include <string.h>


struct Date {
    int day;
    int month;
    int year;
};

struct Event {
    char event_name[100];
    struct Date date; 
    char location[100];
};


void displayEventDetails(struct Event event) {
    printf("Event Name: %s\n", event.event_name);
    printf("Date: %02d/%02d/%04d\n", event.date.day, event.date.month, event.date.year);
    printf("Location: %s\n", event.location);
}

int main() {
    struct Event myEvent;

    printf("Enter event name: ");
    fgets(myEvent.event_name, sizeof(myEvent.event_name), stdin);
    myEvent.event_name[strcspn(myEvent.event_name, "\n")] = 0; 

    printf("Enter event date (dd mm yyyy): ");
    scanf("%d %d %d", &myEvent.date.day, &myEvent.date.month, &myEvent.date.year);

    printf("Enter event location: ");
    getchar();
    fgets(myEvent.location, sizeof(myEvent.location), stdin);
    myEvent.location[strcspn(myEvent.location, "\n")] = 0;

    printf("\nEvent Details:\n");
    displayEventDetails(myEvent);

    return 0;
}