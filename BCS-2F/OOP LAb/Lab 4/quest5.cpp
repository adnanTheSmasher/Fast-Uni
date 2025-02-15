#include<iostream>
using namespace std;

class Employee
{
    private:
        int employeeID;
        string name;
        string department;
        double salary;

    public:
        Employee()
        {
            employeeID = 0;
            name = "";
            department = "";
            salary = 0.0;
        } 

        Employee(int e_ID, string e_name, string e_dept, double e_salary)
        {
            employeeID = e_ID;
            name = e_name;
            department = e_dept;
            salary = e_salary; 
        }

        void giveBonus(double amount)
        {
            if(amount <= 0)
            {
                cout<< "\nInvalid Amount Entered.....\n";
            }    
            else
            {
                salary += amount;
                cout<< "\nBonus Added to Salary....\n";
            }
        }

        bool isManager()
        {
            return department == "Management";
        }

        void displayDetails()
        {
            cout<< "\nEmployee Name: "<< name;
            cout<< "\nEmployee ID: "<< employeeID;
            cout<< "\nEmployee Department: "<< department;
            cout<< "\nEmployee Salary: $"<< salary; 
            cout<< "\nEmployee Is Manager: "<< (isManager()? "True": "False");
        }

};

int main()
{
    Employee e1;
    Employee e2(0656, "Adnan", "Management", 50000);
    Employee e3(0772, "Hammad", "IT", 45000);

    cout<<"\n----------------\n";
    e1.displayDetails();
    cout<<"\n----------------\n";
    e2.displayDetails();
    e2.giveBonus(50000);
    e2.displayDetails();
    cout<<"\n----------------\n";
    e3.displayDetails();
}