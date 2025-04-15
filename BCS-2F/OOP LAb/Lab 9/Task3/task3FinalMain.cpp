//compile and run in powershell: g++ "task3FinalMain.cpp" "task3Header.cpp" -o task3.exe



#include "task3Header.h"
#include <iostream>
using namespace std;

class Library
{
private:
    Book** books;
    int bookCount;
    int capacity;

public:    
    Library(int cap) : bookCount(0), capacity(cap) {
        books = new Book*[capacity]; 
    }

    ~Library() { 
        for (int i = 0; i < bookCount; i++) {
            delete books[i]; 
        }
        delete[] books; 
    }

    void AddBook()
    {
        if (bookCount >= capacity) {
            cout << "Library is full, cannot add more books." << endl;
            return; 
        }

        string title, author, ISBN;
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Book Author: ";
        cin >> author;
        cout << "Enter Book ISBN: ";
        cin >> ISBN;

        books[bookCount++] = new Book(title, author, ISBN);
       
    }
    
    void RemoveBook()
    {
        string title;
        cout << "Enter Book Title: ";
        cin >> title;
        
        for (int i = 0; i < bookCount; i++) {
            if (title == books[i]->getTitle()) {
                delete books[i]; 

               
                for (int j = i; j < bookCount - 1; j++) {
                    books[j] = books[j + 1];
                }

                bookCount--; 
                cout << "Book removed successfully." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;     
    }
    
    void SearchBook()
    {
        string title;
        cout << "Enter Book Title: ";
        cin >> title;
        
        for (int i = 0; i < bookCount; i++) {
            if (title == books[i]->getTitle()) {
                cout << "Book Found - Details Below\n";
                cout << "Title: " << books[i]->getTitle() << endl;
                cout << "Author: " << books[i]->getAuthor() << endl;
                cout << "ISBN: " << books[i]->getISBN() << endl;
                return; 
            }
        }
        cout << "Book not found." << endl;     
    }
};

int main()
{
    Library library(10); 

    library.AddBook(); 
    library.RemoveBook(); 
    library.SearchBook();

    return 0;
}
