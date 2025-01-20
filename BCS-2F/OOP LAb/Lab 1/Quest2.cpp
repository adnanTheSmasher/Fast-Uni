#include<iostream>
using namespace std;

struct Students{
    int stdId;
    float Maths_Marks;
    float Sci_Marks;
    float Eng_Marks;
    string Grade;
    float Avg;
    float Total_Marks;
};

int main()
{
    int num_of_students;
    int i;
    cout<<"Enter Number of Students: ";
    cin>>num_of_students;
    
    struct Students students[num_of_students];

    for(i=0; i<num_of_students; i++)
    {
        cout<<"Enter Student_Id: ";
        cin>>students[i].stdId;
        cout<<"Enter Maths Marks: ";
        cin>>students[i].Maths_Marks;
        cout<<"Enter SCience Marks: ";
        cin>>students[i].Sci_Marks;
        cout<<"Enter English Marks: ";
        cin>>students[i].Eng_Marks;
        students[i].Total_Marks = ((students[i].Maths_Marks + students[i].Sci_Marks + students[i].Eng_Marks) * 100) / 300;
        students[i].Avg =(students[i].Maths_Marks + students[i].Sci_Marks + students[i].Eng_Marks) / 3;
    }
    
    for(i=0; i<num_of_students; i++){
    	if(students[i].Total_Marks > 90){
    		students[i].Grade = "A";
		}
		else if(students[i].Total_Marks > 80 and students[i].Total_Marks < 89){
    		students[i].Grade = "B";
		}
		else if(students[i].Total_Marks > 70 and students[i].Total_Marks < 79){
    		students[i].Grade = "C";
		}
		else if(students[i].Total_Marks > 60 and students[i].Total_Marks < 69){
    		students[i].Grade = "D";
		}
		else if(students[i].Total_Marks < 59){
    		students[i].Grade = "F";
		}
	}
	
	for(i=0; i<num_of_students; i++)
    {
        cout<<"Student_Id: "<< students[i].stdId <<endl;
        cout<< "Grade: "<< students[i].Grade <<" Maths Marks: " << students[i].Maths_Marks << "\t"<< " Science Marks: " << students[i].Sci_Marks << "\t" << " English Marks: " << students[i].Eng_Marks << "\t" << "Total Marks: " << students[i].Total_Marks << "\t" << "Average Marks: " << students[i].Avg <<endl;
	}
    
	
    
}
