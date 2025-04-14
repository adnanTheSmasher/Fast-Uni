#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;

// Base class for User
class User {
protected:
    char name[30];
    char mobile[15];
    char address[50];

public:
    virtual void accept() = 0; // Pure virtual function
    virtual void display() = 0; // Pure virtual function
};

// Class for Password Management
class PasswordManager {
private:
    char password[20];

public:
    void setPassword(int code) {
        if (code == 1234) {
            cout << "\nEnter password (less than 10 characters): ";
            cin.ignore();
            cin.getline(password, 20);
            fstream wr;
            wr.open("pass.txt", ios::out);
            wr.write((char*)this, sizeof(PasswordManager));
            wr.close();
        } else {
            cout << "\nCode Error";
        }
    }

    bool checkPassword() {
        char input[20];
        cout << "\nEnter password: ";
        for (int i = 0; i < strlen(password); i++) {
            input[i] = getch();
            cout << "*";
        }
        input[strlen(password)] = '\0';
        return stricmp(input, password) == 0;
    }
};

// Class for Hotel Room
class HotelRoom : public User {
private:
    int room_no;
    char date[15];
    char adhar[15];

public:
    void accept() override {
        cin.ignore();
        cout << "\nEnter date: ";
        cin.getline(date, 15);
        cout << "\nEnter full name: ";
        cin.getline(name, 30);
        cout << "\nEnter mobile number: ";
        cin >> mobile;
        cin.ignore();
        cout << "\nEnter Aadhar card number: ";
        cin.getline(adhar, 15);
        cout << "\nEnter address: ";
        cin.getline(address, 50);
    }

    void display() override {
        cout << "\nRoom number: " << room_no;
        cout << "\nName: " << name;
        cout << "\nMobile number: " << mobile;
        cout << "\nAadhar card number: " << adhar;
        cout << "\nAddress: " << address;
        cout << "\n----------------------------";
    }

    void setRoomNumber(int r) {
        room_no = r;
    }

    int getRoomNumber() {
        return room_no;
    }
};

// Class for Hotel Management
class HotelManagement {
private:
    HotelRoom room;
    PasswordManager passwordManager;

public:
    void bookRoom() {
        int r;
        cout << "\nEnter room number: ";
        cin >> r;
        if (checkRoomAvailability(r)) {
            room.setRoomNumber(r);
            room.accept();
            fstream wr;
            wr.open("record.txt", ios::app);
            wr.write((char*)&room, sizeof(room));
            wr.close();
        } else {
            cout << "\nROOM ALREADY BOOKED";
        }
    }

    void viewAllRooms() {
        fstream rd;
        rd.open("record.txt", ios::in);
        while (rd.read((char*)&room, sizeof(room))) {
            room.display();
        }
        rd.close();
    }

    void changePassword() {
        int code;
        cout << "\nEnter passcode: ";
        cin >> code;
        passwordManager.setPassword(code);
    }

    void viewRoomStatus() {
        if (passwordManager.checkPassword()) {
            viewAllRooms();
        } else {
            cout << "\nPassword Mismatch";
        }
    }

private:
    bool checkRoomAvailability(int r) {
        fstream rd;
        rd.open("record.txt", ios::in);
        while (rd.read((char*)&room, sizeof(room))) {
            if (r == room.getRoomNumber()) {
                rd.close();
                return false; // Room is already booked
            }
        }
        rd.close();
        return true; // Room is available
    }
};

// Main function
int main() {
    HotelManagement hotel;
    int choice;
    while (true) {
        cout << "\n\t\tWELCOME TO HOTEL MANAGEMENT PROJECT\n ";
        cout << "\t\t_______________________________________ ";
        cout << "\n\t\t1. Book a room";
        cout << "\n\t\t2. View all rooms status";
        cout << "\n\t\t3. Change password";
        cout << "\n\t\t4. View room status";
        cout << "\n\t\t5. Exit";
        cout << "\nSelect your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.bookRoom();
                break;
            case 2:
                hotel.viewAllRooms();
                break;
            case 3:
                hotel.changePassword();
                break;
            case 4:
                hotel.viewRoomStatus();
                break;
            case 5:
                cout << "\nBYE BYE !!!";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.";
        }
    }
}