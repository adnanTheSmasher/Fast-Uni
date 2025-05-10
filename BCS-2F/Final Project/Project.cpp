#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <map>
using namespace std;

class LanguageManager {
private:
    map<string, string> translations;
public:
    void loadLanguage(const string& languageFile) {
        ifstream file(languageFile);
        string line;
        while (getline(file, line)) {
            size_t delimiterPos = line.find('=');
            if (delimiterPos != string::npos) {
                string key = line.substr(0, delimiterPos);
                string value = line.substr(delimiterPos + 1);
                translations[key] = value;
            }
        }
        file.close();
    }
    string getTranslation(const string& key) {
    if (translations.find(key) != translations.end()) {
        return translations[key];
    } else {
        cout << "Translation key not found: " << key << endl; // Debug statement
        return key; // Return the key itself if not found
    }
}
};

void printLine(char ch, int length) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    cout << endl;
}
void printHeader(const string& title) {
    printLine('=', 50);
    cout << "\t\t" << title << endl;
    printLine('=', 50);
}

string languageChecker(string languageChoice){
    if (languageChoice == "en") {
        return "en.txt";
    } else if (languageChoice == "es") {
        return "es.txt";
    } else {
        cout << "Idioma no soportado. Usando inglés por defecto.\n";
        return "en.txt";
    }
}

// Base class for User
class User {
protected:
    char name[30];
    char mobile[15];
    char address[50];

public:
    virtual void accept(string langChoice) = 0; // Pure virtual function
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
protected:
    int room_no;
    char checkInDate[15]; // New attribute for check-in date
    char checkOutDate[15];
    char Shanakti[15];
    char roomType[20];
    LanguageManager LangManager;

public:
    void accept(string langChoice) override {
    
    //langChoice = languageChecker(langChoice);
    LangManager.loadLanguage(langChoice);

    cin.ignore();
    cout << LangManager.getTranslation("ENTER_CheckIn_DATE") << endl; // Debug statement
    cin.getline(checkInDate, 15);
    cout << LangManager.getTranslation("ENTER_CheckOut_DATE") << endl; // Debug statement
    cin.getline(checkOutDate, 15);
    cout << LangManager.getTranslation("Enter_Room_TYPE") << endl; // Debug statement
    cin.getline(roomType, 20);
    cout << LangManager.getTranslation("ENTER_FULL_NAME") << endl; // Debug statement
    cin.getline(name, 30);
    cout << LangManager.getTranslation("ENTER_MOBILE_NUMBER") << endl; // Debug statement
    cin >> mobile;
    cin.ignore();
    cout << LangManager.getTranslation("ENTER_SHANAKTI_CARD") << endl; // Debug statement
    cin.getline(Shanakti, 15);
    cout << LangManager.getTranslation("ENTER_ADDRESS") << endl; // Debug statement
    cin.getline(address, 50);
}


    void display() override {
        cout << "\nRoom number: " << room_no;
        cout << "\nName: " << name;
        cout << "\nMobile number: " << mobile;
        cout << "\nShanakti card number: " << Shanakti;
        cout << "\nAddress: " << address;
        cout << "\n----------------------------";
    }

    const char* getName() {
        return name;
    }
    // Getter for Shanakti card number
    const char* getShanakti() {
        return Shanakti;
    }
    // Getter for mobile number
    const char* getMobile() {
        return mobile;
    }
    // Getter for address
    const char* getAddress() {
        return address;
    }
    const char* getCheckInDate() {
        return checkInDate;
    }
    const char* getCheckOutDate() {
        return checkOutDate;
    }
    void setRoomNumber(int r) {
        room_no = r;
    }
    const char* getRoomType() {
        return roomType;
    }
    int getRoomNumber() {
        return room_no;
    }
};

// Function to write booking details to CSV
void writeBookingToCSV(HotelRoom& room) {
    fstream wr;
    wr.open("record.csv", ios::app); // Open in append mode
    // Check if the file is empty to write headers
    if (wr.tellp() == 0) {
        wr << "Room Number,Check-In Date,Check-Out Date,Name,Mobile Number,Shanakti Card Number,Address\n";
    }
    // Write the booking details in a formatted manner
    wr << room.getRoomNumber() << ","
       << "\"" << room.getCheckInDate() << "\"," // Quotes for text fields
       << "\"" << room.getCheckOutDate() << "\"," // Quotes for text fields
       << "\"" << room.getName() << "\"," // Quotes for text fields
       << "\"" << room.getMobile() << "\"," // Quotes for text fields
       << "\"" << room.getShanakti() << "\"," // Quotes for text fields
       << "\"" << room.getAddress() << "\"\n"; // Quotes for text fields
    wr.close();
}

// Class for Hotel Management
class HotelManagement {
private:
    HotelRoom room;
    PasswordManager passwordManager;
    LanguageManager langManager;

public:
   void bookRoom(string lang) {
    int r;
    langManager.loadLanguage(lang);
    cout << langManager.getTranslation("ENTER_ROOM_NUMBER");
    cin >> r;
    if (checkRoomAvailability(r)) {
        room.setRoomNumber(r);
        room.accept(lang);
        writeBookingToCSV(room); // Call the function to write to CSV
        
        printHeader("Booking Successful");
        cout << "Your room has been booked successfully!" << endl;
    } else {
        printHeader("Booking Failed");
        cout << "Room is already booked. Please choose another room." << endl;
    }
}



    void cancelBooking(string lang) {
    //lang = languageChecker(lang);
    langManager.loadLanguage(lang);
    int r;
    cout << langManager.getTranslation("ENTER_ROOM_NUMBER");
    cin >> r;
    // Logic to remove the booking from the CSV file
    // This can be done by reading the file, skipping the entry, and writing back the remaining entries
    fstream rd, wr;
    rd.open("record.csv", ios::in);
    wr.open("temp.csv", ios::out);
    string line;
    bool found = false;
    while (getline(rd, line)) {
        if (line.find(to_string(r)) != string::npos) {
            found = true; // Room found for cancellation
            continue; // Skip writing this line
        }
        wr << line << endl; // Write remaining lines to temp file
    }
    rd.close();
    wr.close();
    remove("record.csv"); // Remove original file
    rename("temp.csv", "record.csv"); // Rename temp file to original
    if (found) {
        cout << langManager.getTranslation("BOOKING_CANCELLED");
    } else {
        cout << langManager.getTranslation("ROOM_NOT_FOUND");
    }
}

    void viewAllRooms() {
    fstream rd;
    rd.open("record.csv", ios::in);
    string line;
    bool isFirstLine = true; // Flag to check if it's the first line

    while (getline(rd, line)) {
        // Print the header only once
        if (isFirstLine) {
            cout << line << endl; // Print the header
            isFirstLine = false; // Set the flag to false after printing the header
        } else {
            cout << line << endl; // Print the room records
        }
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

    void processPayment(string lang) {
    //lang = languageChecker(lang);
    langManager.loadLanguage(lang);
    float amount;
    cout << langManager.getTranslation("ENTER_PAYMENT_AMOUNT");
    cin >> amount;
    cout << langManager.getTranslation("PROCESSING_PAYMENT") << "...\n";
    // Simulate payment processing
    cout << langManager.getTranslation("PAYMENT_SUCCESSFUL");
}


private:
    bool checkRoomAvailability(int r) {
        fstream rd;
        rd.open("record.csv", ios::in); // Open in read mode
        if (!rd.is_open()) {
            // If the file doesn't exist, create it
            rd.clear(); // Clear any error flags
            rd.open("record.csv", ios::out); // Open in write mode to create the file
            rd.close(); // Close the file after creating
            return true; // Room is available since the file was created
        }
        
        string line;
        while (getline(rd, line)) {
            // Split the line by commas to get the room number
            size_t pos = line.find(',');
            if (pos != string::npos) {
                string roomNumberStr = line.substr(0, pos); // Get the room number part
                if (roomNumberStr == to_string(r)) {
                    rd.close();
                    return false; // Room is already booked
                }
            }
        }
        rd.close();
        return true; // Room is available
    }



};



int main() {
    LanguageManager langManager;
    HotelManagement hotel;
    string languageChoice;

    cout << "Seleccione el idioma (en/es): ";
    cin >> languageChoice;

    //languageChoice = languageChecker(languageChoice);
    langManager.loadLanguage(languageChoice);

    int choice;
    while (true) {
        printHeader(langManager.getTranslation("WELCOME"));
        cout << "\n\t\t1. " << langManager.getTranslation("BOOK_ROOM");
        cout << "\n\t\t2. " << langManager.getTranslation("VIEW_ROOMS");
        cout << "\n\t\t3. " << langManager.getTranslation("CHANGE_PASSWORD");
        cout << "\n\t\t4. " << langManager.getTranslation("VIEW_ROOM_STATUS");
        cout << "\n\t\t5. " << langManager.getTranslation("CANCEL_BOOKING");
        cout << "\n\t\t6. " << langManager.getTranslation("PROCESS_PAYMENT");
        cout << "\n\t\t7. " << langManager.getTranslation("EXIT");
        cout << "\n" << langManager.getTranslation("SELECT_CHOICE") << " ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.bookRoom(languageChoice);
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
                hotel.cancelBooking(languageChoice); // Call cancel booking
                break;
            case 6:
                hotel.processPayment(languageChoice); // Call payment processing
                break;
            case 7:
                cout << "\n" << langManager.getTranslation("EXIT") << " !!!";
                return 0;
            default:
                cout << "\n" << langManager.getTranslation("INVALID_CHOICE");
        }
    }
}
