#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Resume{
    string name;
    string email;
    int yearsOfExperience;
    string summary;
};

int main() {
    Resume resume;

    cout << "Enter details for Resume:\n";
    cout << "name: ";
    getline(cin, resume.name);
    cout << "Email: "; 
    getline(cin, resume.email);
    cout << "yearsOfExperience: ";
    cin >> resume.yearsOfExperience;
    cout << "Summary: ";
    cin.ignore();
    getline(cin, resume.summary);
    cout << endl;


    ofstream outFile("resume.txt", ios::trunc | ios::out);
    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << "Name: " << resume.name << "\n"
            << "Email: " << resume.email << "\n"
            << "Years of Experience: " << resume.yearsOfExperience << "\n"
            << "Summary: " << resume.summary << "\n";
    

    outFile.close();

    ifstream inFile("resume.txt", ios::in);
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