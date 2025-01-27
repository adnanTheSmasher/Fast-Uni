#include<iostream>
#include<cstring>
using namespace std;

struct Register{
	int studentId;
	string firstName;
	string lastName;
	string cellNo;
	string email;
};

struct Student{
	Register reg;
	int courseId;
	string courseName;
};

int main()
{
	Student student[5];
	
	for(int i=0; i<1; i++)
	{
		cout<<"Enter Student First name: ";
		cin>>student[i].reg.firstName;
		cout<<"Enter Student Last name: ";
		cin>>student[i].reg.lastName;
		cout<<"Enter Student student_ID: ";
		cin>>student[i].reg.studentId;
		cout<<"Enter Student Course Id: ";
		cin>>student[i].courseId;
		cout<<"Enter Student Course Name: ";
		cin>>student[i].courseName;
		cout<<"Enter Student Cell-No: ";
		cin>>student[i].reg.cellNo;
		cout<<"Enter Student Email: ";
		cin>>student[i].reg.email;
	}
	
	
	for(int i=0; i<1; i++)
	{
		cout<<"\n--- Student Info [" <<i<<"]---\n";
		cout<<"Student First name: "<<student[i].reg.firstName<<endl;
		cout<<"Student Last name: "<<student[i].reg.lastName<<endl;
		cout<<"Student student_ID: "<<student[i].reg.studentId<<endl;
		cout<<"Student Course Id: "<<student[i].courseId<<endl;
		cout<<"Student Course Name: "<<student[i].courseName<<endl;
		cout<<"Student Cell-No: "<<student[i].reg.cellNo<<endl;
		cout<<"Student Email: "<<student[i].reg.email<<endl;
	}
	
}