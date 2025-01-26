#include <iostream>
#include<string>
using namespace std;

struct Event {
    string name;
    string date; // DD-MM-YYYY
    string venue;
    string organizer;
};

void addEvent(Event* event, int total_num_of_event) {
    for (int i = 0; i < total_num_of_event; i++) {
        cout << "Enter Event Name: ";
        cin.ignore();
        getline(cin, event[i].name);
        cout << "Enter Event Date (DD-MM-YYYY): ";
        getline(cin, event[i].date);
        cout << "Enter Event Venue: ";
        getline(cin, event[i].venue);
        cout << "Enter Event Organizer: ";
        getline(cin, event[i].organizer);
    }
}

void displayEventDetails(Event* event, int total_num_of_event) {
    if (total_num_of_event <= 0) {
        cout << "\n--- No Event Available ---\n";
    }

    cout << "\n--- Event List ---\n";
    for (int i = 0; i < total_num_of_event; i++) {
        cout << "Event Name: " << event[i].name << "\n"
            << "Date: " << event[i].date << "\n"
            << "Venue: " << event[i].venue << "\n"
            << "Organizer: " << event[i].organizer << "\n"
            << "-------------------\n";
    }

}

void searchingEvent(Event* event, int total_num_of_event) {
    string date;
    bool event_Found = false;
    cout << "\n--- Event Searching ---\n";
    cout << "Enter Specific Date to Find Event (DD-MM-YYYY): ";
    cin.ignore();
    getline(cin, date);

    for (int i = 0; i < total_num_of_event; i++) {
        if (event[i].date == date) {
            cout << "Event Name: " << event[i].name << "\n"
                << "Date: " << event[i].date << "\n"
                << "Venue: " << event[i].venue << "\n"
                << "Organizer: " << event[i].organizer << "\n"
                << "-------------------\n";
            event_Found = true;
        }
    }
    if (!event_Found) {
        cout << "No events found for the specified date.\n";
    }

}

int main()
{
    int total_num_of_Events;
    cout << "Enter the total number of events manage: ";
    cin >> total_num_of_Events;

    Event* event = new Event[total_num_of_Events];

    int choice;
    do {
        cout << "\n--- Event Management System ---\n";
        cout << "1. Add Event\n";
        cout << "2. Display All Events\n";
        cout << "3. Search Events by Date\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
                addEvent(event, total_num_of_Events);
            break;
        case 2:
            displayEventDetails(event, total_num_of_Events);
            break;
        case 3: {
            searchingEvent(event, total_num_of_Events);
            break;
        }
        case 4:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

