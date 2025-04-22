#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
    ifstream chapter1("Chapter1.txt");
    ifstream chapter2("Chapter2.txt");
    ofstream book("Book.txt", ios::out);

    string line;
    while(getline(chapter1, line))
    {
        book << line <<endl;
    }
    book << "\n\n";
    while(getline(chapter2, line))
    {
        book<< line<<endl;
    }

    chapter1.close();
    chapter2.close();
    book.close();

    cout<< "Successfully Concanetated....";

}