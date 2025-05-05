#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
class FileException : public exception {
public:
    virtual const char* what() const noexcept {
        return "File Exception occurred";
    }
};

class FileNotFoundException : public FileException {
public:
    const char* what() const noexcept override {
        return "FileNotFoundException: File not found!";
    }
};

class PermissionDeniedException : public FileException {
public:
    const char* what() const noexcept override {
        return "PermissionDeniedException: Access denied!";
    }
};

void readFile(const string& filename) {
    if (filename == "missing.txt") {
        throw FileNotFoundException();
    } else if (filename == "secret.txt") {
        throw PermissionDeniedException();
    }
    cout << "File read successfully!" << endl;
}

int main() {
    try {
        readFile("secret.txt");
    } catch (const FileException& e) {
        cout << "Reading 'secret.txt': " << e.what() << endl;
    }
    
    try {
        readFile("missing.txt");
    } catch (const FileException& e) {
        cout << "Reading 'missing.txt': " << e.what() << endl;
    }
    
    return 0;
}