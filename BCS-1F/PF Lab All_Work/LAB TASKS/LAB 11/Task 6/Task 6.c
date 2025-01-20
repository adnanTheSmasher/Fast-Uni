#include<stdio.h>
#include<string.h>

struct Address{
	char city[20];
	int zipCode;
};

struct Employee {
	int id;
    int salary; 
    struct Address address;
};

void read_data_from_file(char fname[]){
	FILE *fptr = fopen(fname, "r");
	
	char line[256];
	printf("\n\nData From Employee File: \n");
	while(fgets(line, sizeof(line), fptr) != NULL){
		printf("%s", line);
	}
	
	fclose(fptr);
}

int main(){
	struct Employee employee[2];
	char fname[] = "Employees.txt"; 
	FILE *fptr = fopen(fname, "a");
	for(int i=0; i<2; i++){
		printf("\nEnter Employee %d ID: ", i+1); scanf("%d", &employee[i].id); 
		printf("Enter Employee %d Salary: ", i+1); scanf("%d", &employee[i].salary); 
		printf("Enter Employee %d City: ", i+1); scanf("%s", &employee[i].address.city);
		printf("Enter Employee %d Zip Code: ", i+1); scanf("%d", &employee[i].address.zipCode);
		
		fprintf(fptr, "Employee %d ID: %d\n", i+1, employee[i].id); 
		fprintf(fptr, "Employee %d Salary: %d$\n", i+1, employee[i].salary);
		fprintf(fptr, "Employee %d City: %s\n", i+1, employee[i].address.city);
		fprintf(fptr, "Employee %d Zip Code: %d\n\n", i+1, employee[i].address.zipCode);
	}
	
	fclose(fptr);	
	read_data_from_file(fname);
}