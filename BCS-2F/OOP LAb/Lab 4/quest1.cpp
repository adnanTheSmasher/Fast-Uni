#include<iostream>
using namespace std;

class Student{
	private:
		int student_Id;
		string name;
		int age;
		char grade;
	public:
		Student(){
			student_Id = 0;
			name = "";
			age = 0;
			grade = 'N';
			
		}
		Student(int std_id, string std_name, int std_age, char grd){
			student_Id = std_id;
			name = std_name;
			age = std_age;
			grade = grd;
		}
		
		void promoteStudent(){
			if(grade == 'A')
				cout<<"Grade cannot be Promoted.... Grade is "<< grade;
			else{
				grade--;
			}
		}
		
		
		void displayDetails(){
			cout<<"Student ID: "<<student_Id<<endl;
			cout<<"Stuent Name: "<<name<<endl;
			cout<<"Student Age: "<<age<<endl;
			cout<<"Student Grade: "<<grade<<endl;
		}
		
		bool isEligibleForScholarship(){
			if(grade == 'A'){
				return true;
			}
		}
};


int main(){
	Student student1;
	Student student2(0656, "Adnan", 18, 'B');
	
	student1.displayDetails();
	
	cout<<"\n-------------------\n";
	student2.displayDetails();
	int eligible;
	cout << "Eligible for Scholarship: " << (student2.isEligibleForScholarship() ? "true" : "false");
		
	student2.promoteStudent();
	student2.displayDetails();
	cout << "Eligible for Scholarship: " << (student2.isEligibleForScholarship() ? "true" : "false");
	
	
}