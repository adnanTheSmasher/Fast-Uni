#include <stdio.h>

int main() {
    float gpa;

    printf("Enter GPA: ");
    scanf("%f", &gpa);

  	 	(gpa >= 3.5 && gpa <= 4.0) ? printf("Highest honors for Semester") :
                 (gpa >= 3.0 && gpa <= 3.49) ? printf("Dean's list for semester") :
                 (gpa >= 2.0 && gpa <= 2.99) ? printf(".") :
                 (gpa >= 1.0 && gpa <= 1.99) ? printf("ON probabation for next semester") :
                 (gpa >= 0.0 && gpa <= 0.99) ? printf("Failed semester - registration suspended") :
                 'Invalid GPA';


    return 0;
}