#include<stdio.h>

struct Marks{
	int math;
	int science;
	int english;
};
struct Student{
	int roll_no;
	char name[20];
	struct Marks marks;
};


int main(){
	struct Student student[5];
	float avg = 0;
	float sum = 0; 
	for(int i=0;i<5;i++){
		printf("Enter roll no: "); scanf("%d", &student[i].roll_no);
		printf("Enter Name: "); scanf("%s", &student[i].name);
		printf("Enter Marks For Maths: "); scanf("%d", &student[i].marks.math);
		printf("Enter Marks For Science: "); scanf("%d", &student[i].marks.science);
		printf("Enter Marks For English: "); scanf("%d", &student[i].marks.english);
		sum = student[i].marks.math + student[i].marks.english + student[i].marks.science;
		avg = sum/3.0;
		printf("THe Average marks of student %s (%d): %.2f\n", student[i].name, student[i].roll_no, avg);
	}
	
}