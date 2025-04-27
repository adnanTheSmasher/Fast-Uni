#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    fstream file("task5.txt", ios::in | ios::out);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    string searchWord;
    string replacementWord;

    cout << "Enter word to search: " << endl;
    cin >> searchWord;

    cout << "Enter word to replace: " << endl;
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word should be of equal or smaller length." << endl;
        return 0;
    }

    file.seekg(0);
    streampos pos;
    string word;
    bool found = false;

    while (file >> word) {
        if (word == searchWord) {
            pos = file.tellg();
            pos -= word.length(); 
            found = true;
            cout << "Word located at: " << pos << endl;
            break;
        }
    }

    if (found) {
        
        file.seekp(pos);

        
        file << replacementWord;

        
        if (replacementWord.length() < searchWord.length()) {
            size_t padding = searchWord.length() - replacementWord.length();
            file << string(padding, ' ');
        }
    } else {
        cout << "Word not found." << endl;
    }

    
    file.seekg(0);
    cout << "\nUpdated file content:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}