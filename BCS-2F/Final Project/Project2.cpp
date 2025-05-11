/*
  Refactored: Project.cpp with Centered Terminal UI
  Enhancements:
  - Centered all UI output and user input
  - Centered Python script output
  - No external libraries used
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns = 80;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return columns;
}

void printLine(char ch, int length) {
    cout << string(length, ch) << endl;
}

void printCentered(const string& text, const string& color = "") {
    int consoleWidth = getConsoleWidth();
    int padding = (consoleWidth - text.length()) / 2;
    if (padding < 0) padding = 0;
    cout << color << string(padding, ' ') << text << RESET << endl;
}

void centeredInput(const string& prompt, string& input, const string& color = CYAN) {
    int width = getConsoleWidth();
    int padding = (width - prompt.length() - 10) / 2;
    if (padding < 0) padding = 0;
    cout << color << string(padding, ' ') << prompt << RESET;
    getline(cin, input);
}

template <typename T>
void centeredCin(const string& prompt, T& input, const string& color = CYAN) {
    int width = getConsoleWidth();
    int padding = (width - prompt.length() - 10) / 2;
    if (padding < 0) padding = 0;
    cout << color << string(padding, ' ') << prompt << RESET;
    cin >> input;
    cin.ignore();
}

void runPythonCentered(const string& command) {
    FILE* pipe = _popen(command.c_str(), "r");
    if (!pipe) {
        printCentered("Error running command", RED);
        return;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe)) {
        string line(buffer);
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        printCentered(line);
    }
    _pclose(pipe);
}

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
            printCentered("Translation key not found: " + key);
            return key;
        }
    }
};

void printHeader(const string& title) {
    system("cls");
    int width = getConsoleWidth();
    printLine('=', width);
    printCentered(title, CYAN BOLD);
    printLine('=', width);
}

string languageChecker(string languageChoice) {
    if (languageChoice == "en") return "en.txt";
    else if (languageChoice == "es") return "es.txt";
    else if (languageChoice == "fr") return "fr.txt";
    printCentered("Unsupported language. Defaulting to English.");
    return "en.txt";
}

class User {
protected:
    char name[30], mobile[15], address[50];
public:
    virtual void accept(string langChoice) = 0;
    virtual void display() = 0;
};

class PasswordManager {
private:
    char password[20];
    LanguageManager langManager;
public:
    void setPassword(int code, string language) {
        langManager.loadLanguage(language);
        if (code == 1234) {
            printCentered(langManager.getTranslation("PASSWORD_ENTER"), RED);
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

       bool checkPassword(string language) {
        langManager.loadLanguage(language);
        char input[20];
        printCentered(langManager.getTranslation("PASSWORD"), RED);
        for (int i = 0; i < strlen(password); i++) {
            input[i] = getch();
            cout << "*";
        }
        input[strlen(password)] = '\0';
        return stricmp(input, password) == 0;
    }


   
};

class HotelRoom : public User {
protected:
    int room_no;
    char checkInDate[15], checkOutDate[15], Shanakti[15];
public:
    char roomType[20];
    void accept(string langChoice) override {
        LanguageManager LangManager;
        LangManager.loadLanguage(langChoice);
        string input;
        centeredInput(LangManager.getTranslation("ENTER_CheckIn_DATE"), input);
        strcpy(checkInDate, input.c_str());
        centeredInput(LangManager.getTranslation("ENTER_CheckOut_DATE"), input);
        strcpy(checkOutDate, input.c_str());
        centeredInput(LangManager.getTranslation("ENTER_FULL_NAME"), input);
        strcpy(name, input.c_str());
        centeredInput(LangManager.getTranslation("ENTER_MOBILE_NUMBER"), input);
        strcpy(mobile, input.c_str());
        centeredInput(LangManager.getTranslation("ENTER_SHANAKTI_CARD"), input);
        strcpy(Shanakti, input.c_str());
        centeredInput(LangManager.getTranslation("ENTER_ADDRESS"), input);
        strcpy(address, input.c_str());
    }
    void display() override {
        printCentered("Room No: " + to_string(room_no));
        printCentered("Name: " + string(name));
        printCentered("Mobile: " + string(mobile));
        printCentered("Shanakti: " + string(Shanakti));
        printCentered("Address: " + string(address));
    }
    const char* getName() { return name; }
    const char* getShanakti() { return Shanakti; }
    const char* getMobile() { return mobile; }
    const char* getAddress() { return address; }
    const char* getCheckInDate() { return checkInDate; }
    const char* getCheckOutDate() { return checkOutDate; }
    void setRoomNumber(int r) { room_no = r; }
    const char* getRoomType() { return roomType; }
    int getRoomNumber() { return room_no; }
};

void writeBookingToExcel(HotelRoom& room) {
    string command = "python write_to_excel.py " + to_string(room.getRoomNumber()) + " " +
                    room.getCheckInDate() + " " + room.getCheckOutDate() + " " +
                    room.getName() + " " + room.getMobile() + " " +
                    room.getShanakti() + " " + room.getAddress();
    system(command.c_str());
}

class HotelManagement {
private:
    HotelRoom room;
    PasswordManager passwordManager;
    LanguageManager langManager;

    bool checkRoomAvailability(int r) {
        if (r <= 0) return false;
        string command = "python read_rom_excel.py " + to_string(r);
        FILE* pipe = _popen(command.c_str(), "r");
        if (!pipe) return false;
        char buffer[128];
        string result = "";
        while (fgets(buffer, sizeof(buffer), pipe)) result += buffer;
        _pclose(pipe);
        result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
        return result == "True";
    }

public:
    void bookRoom(string lang) {
        cout<< RESET;
        int r;
        langManager.loadLanguage(lang);
        runPythonCentered("python listAvailable_rooms.py");
        centeredCin(langManager.getTranslation("ENTER_ROOM_NUMBER"), r);
        if (checkRoomAvailability(r)) {
            room.setRoomNumber(r);
            string getRoomTypeCmd = "python get_room_type.py " + to_string(r);
            FILE* pipe = _popen(getRoomTypeCmd.c_str(), "r");
            if (!pipe) return;
            char buffer[128]; string roomType = "";
            while (fgets(buffer, sizeof(buffer), pipe)) roomType += buffer;
            _pclose(pipe);
            roomType.erase(remove_if(roomType.begin(), roomType.end(), ::isspace), roomType.end());
            strcpy(room.roomType, roomType.c_str());
            room.accept(lang);
            writeBookingToExcel(room);
            printHeader("Booking Successful");
            printCentered(langManager.getTranslation("BOOKING_SUCCESSFULLY"), GREEN);
        } else {
            printHeader("Booking Failed");
            printCentered(langManager.getTranslation("BOOKING_FAILED"), RED);
        }
    }

    void cancelBooking(string lang) {
        cout<< RESET;
        langManager.loadLanguage(lang);
        int r;
        centeredCin(langManager.getTranslation("ENTER_ROOM_NUMBER"), r);
        string command = "python cancelBooking.py " + to_string(r);
        FILE* pipe = _popen(command.c_str(), "r");
        if (!pipe) return;
        char buffer[128]; string result = "";
        while (fgets(buffer, sizeof(buffer), pipe)) result += buffer;
        _pclose(pipe);
        if (result == "True\n") printCentered(langManager.getTranslation("BOOKING_CANCELLED"), GREEN);
        else printCentered(langManager.getTranslation("ROOM_NOT_FOUND"), RED);
    }

    void viewAllRooms() {
        cout<< RESET;
        runPythonCentered("python view_room.py");
    }

    void changePassword(string lang) {
        cout<< RESET;
        langManager.loadLanguage(lang);
        int code;
        cout<< langManager.getTranslation("PASSWORD");
        cin >> code;
        passwordManager.setPassword(code, lang);
    }

    void viewRoomStatus(string language) {
        langManager.loadLanguage(language);
        if (passwordManager.checkPassword(language)) {
            int room_number;
        printCentered(langManager.getTranslation("ROOM_STATUS_FIND"), CYAN);
        cin >> room_number;
        // Call the Python script to get room details
        string command = "python view_room_status.py " + to_string(room_number);
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            cerr << "Failed to run command\n";
            return; // Handle error
        }
        char buffer[128];
        string result = "";
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer; // Read the output from the command
        }
        pclose(pipe);
        // Print the result (room details) received from the Python script
        cout << result;
    }
}

    void processPayment(string lang) {
        cout<< RESET;
        langManager.loadLanguage(lang);
        float amount;
        centeredCin(langManager.getTranslation("ENTER_PAYMENT_AMOUNT"), amount);
        printCentered(langManager.getTranslation("PROCESSING_PAYMENT") + "...\n");
        printCentered(langManager.getTranslation("PAYMENT_SUCCESSFUL"), GREEN);
    }
};

int main() {
    LanguageManager langManager;
    HotelManagement hotel;
    string languageChoice;
    printCentered("Seleccione el idioma (en/es/fr): ");
    cin >> languageChoice;
    langManager.loadLanguage(languageChoice);
    int choice;
    while (true) {
        printHeader(langManager.getTranslation("WELCOME"));
        printCentered("1. " + langManager.getTranslation("BOOK_ROOM"), GREEN);
        printCentered("2. " + langManager.getTranslation("VIEW_ROOMS"), GREEN);
        printCentered("3. " + langManager.getTranslation("CHANGE_PASSWORD"), GREEN);
        printCentered("4. " + langManager.getTranslation("VIEW_ROOM_STATUS"), GREEN);
        printCentered("5. " + langManager.getTranslation("CANCEL_BOOKING"), GREEN);
        printCentered("6. " + langManager.getTranslation("PROCESS_PAYMENT"), GREEN);
        printCentered("7. " + langManager.getTranslation("EXIT"), GREEN);
        cout << endl;
        centeredCin(langManager.getTranslation("SELECT_CHOICE"), choice);
        switch (choice) {
            case 1:
                system("cls"); 
                hotel.bookRoom(languageChoice); 
                break;
            case 2: 
                system("cls");
                hotel.viewAllRooms(); break;
            case 3: system("cls"); hotel.changePassword(languageChoice); break;
            case 4: system("cls"); hotel.viewRoomStatus(languageChoice); break;
            case 5: system("cls"); hotel.cancelBooking(languageChoice); break;
            case 6: system("cls"); hotel.processPayment(languageChoice); break;
            case 7: system("cls"); printCentered(langManager.getTranslation("EXIT") + " !!!", CYAN); return 0;
            default: system("cls"); printCentered(langManager.getTranslation("INVALID_CHOICE"), RED);
        }
        system("pause");
    }
}
