#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;


class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string n, string addr, string phone, string mail) {
        name = n;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    string getName(){
        return name;
    }
};


class Student : public Person {
private:
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, string courses, double gpa, int year)
        : Person(n, i, addr, phone, mail), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo(); 
        cout << "Courses Enrolled: " << coursesEnrolled << endl;
        cout << "GPA: " << fixed << setprecision(2) << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, string courses, double sal)
        : Person(n, i, addr, phone, mail), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo(); 
        cout << "Department: " << department << endl;
        cout << "Courses Taught: " << coursesTaught << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};


class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo(); 
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};


class Course {
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;

public:
    Course(string id, string name, int cr, string instr, string sched)
        : courseId(id), courseName(name), credits(cr), instructor(instr), schedule(sched) {}

    void registerStudent(Student& student) {
        cout << "Registering " << student.getName() << " for the course: " << courseName << endl;
     
    }

    void calculateGrades() {
      
        cout << "Calculating grades for course: " << courseName << endl;
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};


int main() {
  
    Student student("Alice Smith", "S123", "123 Main St", "555-1234", "alice@example.com", "Math, Science", 3.8, 2021);
    Professor professor("Dr. John Doe", "P456", "456 College Ave", "555-5678", "john@example.com", "Mathematics", "Calculus, Algebra", 75000);
    Staff staff("Jane Doe", "ST789", "789 University Blvd", "555-8765", "jane@example.com", "Administration", "Registrar", 50000);

  
    cout << "Student Information:" << endl;
    student.displayInfo();
    cout << endl;

    cout << "Professor Information:" << endl;
    professor.displayInfo();
    cout << endl;

    cout << "Staff Information:" << endl;
    staff.displayInfo();
    cout << endl;

    Course course("C101", "Calculus I", 3, "Dr. John Doe", "Mon/Wed/Fri 10:00-11:00 AM");
    course.displayCourseInfo();
    course.registerStudent(student);
    course.calculateGrades();

    return 0;
}