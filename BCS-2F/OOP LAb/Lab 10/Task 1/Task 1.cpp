#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

int main() {
    const int totalStudents = 5;
    Student students[totalStudents];

    for (int i = 0; i < totalStudents; ++i) {
        cout << "Enter details for student " << (i + 1) << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, students[i].name);
        cout << "GPA: ";
        cin >> students[i].gpa;
        cout << endl;
    }

    ofstream outFile("students.txt", ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < totalStudents; ++i) {
        outFile << "Student ID: " << students[i].id << "\n"
            << "Name: " << students[i].name << "\n"
            << "GPA:  " << students[i].gpa << "\n";
    }
    outFile.close();

 
    ifstream inFile("students.txt", ios::in);
    if (!inFile) {
        cerr << "Error opening file for Reading!" << endl;
        return 1;
    }

    string line;
    while(getline(inFile, line))
    {   
        cout<< line<< endl;
    }

    inFile.close();
 
    return 0;
}