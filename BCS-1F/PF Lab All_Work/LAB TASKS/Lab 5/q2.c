#include <stdio.h>
#include <stdbool.h>

int main() {
	bool weekday, vacation;
	
	printf("Is this Weekday (1 for true or 0 for false): ");
	scanf("%d", &weekday);
	
	printf("Is this Vacation (1 for true or 0 for false): ");
	scanf("%d", &vacation);
	
	if (weekday == true && vacation == false){
		printf("False");
	}
	else if (weekday == false && vacation == true){		
	printf("True");
	}
	else if (weekday == false && vacation == false){
		printf("True");
	}
	else{
		printf("Somehing is wrong with your Input.....");
	}
}