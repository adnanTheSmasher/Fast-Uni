#include<stdio.h>
int main(){
	float distance, total_distance,fuel_going_price, fuel_returning_price, total_fuel_cost, total_fuel_consumed, fuel_avg;
	distance = 1207;
	total_distance = distance * 2;
	fuel_going_price = 118.0;
	fuel_returning_price = 123.0;
	
	printf("Enter your car fuel average: ");
	scanf("%f", &fuel_avg);
	
	if (fuel_avg <= 0)
		printf("Invalid Value of fuel Average, try again...");
	
	total_fuel_consumed = total_distance/fuel_avg;
	
	fuel_going_price = (distance/fuel_avg) * fuel_going_price;
	fuel_returning_price = (distance/fuel_avg) * fuel_returning_price;
	
	total_fuel_cost = fuel_going_price + fuel_returning_price;
	
	printf("total Fuel consumed on total trip is: %.2f\n", total_fuel_consumed);
	printf("Total Fuel cost for whoel trip is: %.2f", total_fuel_cost);
}
