#include<stdio.h>

struct Company{
	char name[20];
	int year_established;
	char depertments[5][20];
};


int main(){
	struct Company company;
	
	printf("Enter Company name: "); 
	fgets(company.name, sizeof(company.name), stdin); 
	company.name[strcspn(company.name, "\n")] = 0;
	
	printf("Enter Year of establishment: "); scanf("%d", &company.year_established);
	getchar();
	for(int i=0;i<5;i++){
		printf("Enter Department %d Name: ", i+1);
		fgets(company.depertments[i], sizeof(company.depertments[i]), stdin); 
		company.depertments[i][strcspn(company.depertments[i], "\n")] = 0;
	}
	
	printf("\n\nCompany Details: \n");
	
	printf("Company name: %s\n", company.name); 
	printf("Year of establishment: %d\n", company.year_established);
	
	for(int i=0;i<5;i++){
		printf("Department %d Name: %s\n", i+1, company.depertments[i]);
	}
	
}