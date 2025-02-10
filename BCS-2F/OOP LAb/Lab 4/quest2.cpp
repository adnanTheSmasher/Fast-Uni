#include<iostream>
using namespace std;

class Book {
    private:
        int Id;
        string title;
        string name;
        bool Availability;

    public:

        Book() {}


        Book(int id, string title, string name, bool Available) {
            this->Id = id;
            this->title = title;
            this->name = name;
            this->Availability = Available;
        }

        Book(int id, string title, string name) {
            this->Id = id;
            this->title = title;
            this->name = name;
        }


        int getId() const {
            return Id;
        }

        void setId(int id) {
            Id = id;
        }

        string getTitle() const {
            return title;
        }

        void setTitle(string title) {
            this->title = title;
        }


        string getName() const {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }


        bool isAvailable() const {
            return Availability;
        }

        void setAvailability(bool available) {
            Availability = available;
        }
};

class Library {
    Book *B1 = new Book[0];
    int noOfBooks = 0;

    public:
        void addBook(Book BN) {
            Book *B = new Book[noOfBooks + 1];

            for (int i = 0; i < noOfBooks; i++) {
                B[i].setId(B1[i].getId());
                B[i].setName(B1[i].getName());
                B[i].setTitle(B1[i].getTitle());
                B[i].setAvailability(B1[i].isAvailable());
            }
            B[noOfBooks].setId(BN.getId());
            B[noOfBooks].setTitle(BN.getTitle());
            B[noOfBooks].setName(BN.getName());
            B[noOfBooks].setAvailability(BN.isAvailable());
            noOfBooks++;
            delete[] B1;
            B1 = B;
        }

        void BorrowBook(int id) {
            for (int i = 0; i < noOfBooks; i++) {
                if (B1[i].getId() == id) {
                    B1[i].setAvailability(false);
                }
            }
        }

        void ReturnBook(int id) {
            for (int i = 0; i < noOfBooks; i++) {
                if (B1[i].getId() == id) {
                    B1[i].setAvailability(true);
                }
            }
        }

        void DisplayBooks() {
            for (int i = 0; i < noOfBooks; i++) {
                cout << "Book " << i + 1 << " : \n" << endl;
                cout << "Book Name : " << B1[i].getName() << endl;
                cout << "Book ID : " << B1[i].getId() << endl;
                cout << "Book Title : " << B1[i].getTitle() << endl;
                cout << "Book Available : " << (B1[i].isAvailable() ? "Yes" : "No") << endl;
            }
        }
};

int main() {
    Library L1;
    Book B1(123, "Science", "Discovery", true);
    Book B2(13, "Wildlife", "Jungle", true);
    L1.addBook(B1);
    L1.addBook(B2);
    L1.DisplayBooks();
    L1.BorrowBook(123);
    L1.DisplayBooks();

    return 0;
}