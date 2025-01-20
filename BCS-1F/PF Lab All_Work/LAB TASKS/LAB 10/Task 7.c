#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int isValidDate(struct Date date) {
    if (date.year < 1) return 0;
    if (date.month < 1 || date.month > 12) return 0; 

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    
    if (isLeapYear(date.year)) {
        daysInMonth[1] = 29;
    }

    return date.day > 0 && date.day <= daysInMonth[date.month - 1];
}


int daysBetween(struct Date start, struct Date end) {
    int totalDays = 0;

    
    for (int year = start.year; year < end.year; year++) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }

    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(start.year)) {
        daysInMonth[1] = 29;
    }
    for (int month = start.month; month <= 12; month++) {
        totalDays -= (month == start.month) ? start.day : 0; 
        totalDays += daysInMonth[month - 1]; 
    }

    
    if (isLeapYear(end.year)) {
        daysInMonth[1] = 29;
    }
    for (int month = 1; month < end.month; month++) {
        totalDays += daysInMonth[month - 1]; 
    }
    totalDays += end.day; 

    return totalDays;
}


int dayOfWeek(struct Date date) {
    
    int day = date.day;
    int month = date.month;
    int year = date.year;

    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int f = day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    return f % 7; 
}


void printDayOfWeek(int day) {
    const char *days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    printf("The day of the week is: %s\n", days[day]);
}

int main() {
    struct Date startDate, endDate;

   
    printf("Enter start date (dd mm yyyy): ");
    scanf("%d %d %d", &startDate.day, &startDate.month, &startDate.year);

   
    printf("Enter end date (dd mm yyyy): ");
    scanf("%d %d %d", &endDate.day, &endDate.month, &endDate.year);

    
    if (!isValidDate(startDate) || !isValidDate(endDate)) {
        printf("One or both of the dates are invalid.\n");
        return 1;
    }

    
    int daysDiff = daysBetween(startDate , endDate);
    printf("Number of days between the two dates: %d\n", daysDiff);

    
    int day = dayOfWeek(startDate);
    printDayOfWeek(day);

    return 0;
}