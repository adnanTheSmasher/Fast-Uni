#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
    ofstream file("info.txt", ios::out);

    file << "C++ is a powerful programming language." << endl;
    file.close();

    fstream file2("info.txt", ios::in | ios::out);

    streampos tellpos = file2.tellg();
    streampos putpos = file2.tellp();
    cout << "Initial get pointer position: " << tellpos << endl;
    cout << "Initial put pointer position: " << putpos << endl;

    string word;
    file2.seekg(9);
    file2 >> word;
    cout << "Word read from position 6: " << word << endl;

    file2.seekp(9);
    file2 << "dynamic";

    streampos tellposNew = file2.tellg();
    streampos putposNew = file2.tellp();
    cout << "New get pointer position: " << tellposNew << endl;
    cout << "New put pointer position: " << putposNew << endl;

    string line;
    file2.seekg(0);
    getline(file2, line);
    cout<< "\nUpdated content\n" << line;






}