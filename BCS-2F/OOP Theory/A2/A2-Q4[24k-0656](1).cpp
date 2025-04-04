#include <iostream>
#include <string>
using namespace std;


unsigned long hashPassword(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = (hash * 33) + c;
    }
    return hash;
}


class User {
protected:
    string name;
    string ID;
    string email;
    unsigned long hashed_password;

public:
    User(string name, string ID, string email, string password) 
        : name(name), ID(ID), email(email) {
        hashed_password = hashPassword(password);
    }

    bool authenticate(const string& password) {
        return hashed_password == hashPassword(password);
    }

    virtual void display() {
        cout << "Name: " << name << ", ID: " << ID << ", Email: " << email << endl;
    }

    virtual bool accessLab() {
        return false; 
    }

    string getName(){return name;}
};


class Student : public User {
private:
    int assignments[10]; 

public:
    Student(string name, string ID, string email, string password) 
        : User(name, ID, email, password) {
        for (int i = 0; i < 10; i++) {
            assignments[i] = 0; 
        }
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < 10) {
            assignments[index] = 1; 
        }
    }

    void display() override {
        User::display();
        cout << "Assignments Status: ";
        for (int i = 0; i < 10; i++) {
            cout << assignments[i] << " ";
        }
        cout << endl;
    }
};


class TA : public Student {
private:
    string assignedStudents[10]; 
    int studentCount; 
    string projects[2]; 
    int projectCount; 

public:
    TA(string name, string ID, string email, string password) 
        : Student(name, ID, email, password), studentCount(0), projectCount(0) {}

    void assignStudent(string studentName) {
        if (studentCount < 10) {
            assignedStudents[studentCount] = studentName; 
            studentCount++;
        } else {
            cout << "Cannot assign more than 10 students." << endl;
        }
    }

    bool addProject(string projectName) {
        if (projectCount < 2) {
            projects[projectCount] = projectName; 
            projectCount++;
            return true;
        } else {
            cout << "TA can only work on 2 projects at a time." << endl;
            return false;
        }
    }

    void display() override {
        Student::display();
        cout << "Assigned Students: ";
        for (int i = 0; i < studentCount; i++) {
            cout << assignedStudents[i] << " ";
        }
        cout << endl;
        cout << "Current Projects: ";
        for (int i = 0; i < projectCount; i++) {
            cout << projects[i] << " ";
        }
        cout << endl;
    }
};


class Professor : public User {
public:
    Professor(string name, string ID, string email, string password) 
        : User(name, ID, email, password) {}

    void assignProjectToTA(TA& ta, string projectName) {
        if (ta.addProject(projectName)) {
            cout << "Project '" << projectName << "' assigned to TA " << ta.getName() << "." << endl;
        } else {
            cout << "Failed to assign project to TA " << ta.getName() << "." << endl;
        }
    }

    void display() override {
        User::display();
    }
};


void authenticateAndPerformAction(User* user, string action, string password) {
    if (user->authenticate(password)) {
        cout << "Authentication successful. Performing action: " << action << endl;
        if (action == "access lab" && user->accessLab()) {
            cout << "Access granted to lab." << endl;
        } else {
            cout << "Action not permitted." << endl;
        }
    } else {
        cout << "Authentication failed." << endl;
    }
}


int main() {
    Student student1("Alice", "S001", "alice@example.com", "password123");
    TA ta1("Bob", "T001", "bob@example.com", "password456");
    Professor prof1("Dr. Smith", "P001", "smith@example.com", "password789");

    student1.display();
    ta1.display();
    prof1.display();


    prof1.assignProjectToTA(ta1, "Project A");
    prof1.assignProjectToTA(ta1, "Project B");
    prof1.assignProjectToTA(ta1, "Project C"); 


    ta1.display();

    authenticateAndPerformAction(&student1, "access lab", "password123");
    authenticateAndPerformAction(&ta1, "access lab", "password456");
    authenticateAndPerformAction(&prof1, "access lab", "wrongpassword");

    return 0;
}