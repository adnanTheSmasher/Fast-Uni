#include <iostream>
#include <string>
using namespace std;


class User {
    protected:
        int user_ID;
        string user_Name;
        bool is_Active;

    public:
        User() : user_ID(0), user_Name(""), is_Active(false) {}
        User(int id, string name) : user_ID(id), user_Name(name), is_Active(false) {}

        string getName() const {
            return user_Name;
        }
        int getID() const {
            return user_ID;
        }
        bool getIsActive() const {
            return is_Active;
        }


        virtual void payFee(float amount) = 0; 
};


class Student : public User {
    private:
        float semester_fee;

    public:
        Student() : User(), semester_fee(0.0) {}
        Student(int std_id, string name) : User(std_id, name), semester_fee(0.0) {}

        void payFee(float amount) override {
            semester_fee += amount;
            if (semester_fee > 100) {
                is_Active = true;
                cout << "Card Activated for Student ID: " << user_ID << endl;
            }
            cout << "Student Fee paid: " << amount << " Total Fee: " << semester_fee << endl;
        }
};


class Teacher : public User {
    private:
        float monthly_fee;

    public:
        Teacher() : User(), monthly_fee(0.0) {}
        Teacher(int tchr_id, string name) : User(tchr_id, name), monthly_fee(0.0) {}

        void payFee(float amount) override {
            monthly_fee += amount;
            is_Active = true; 
            cout << "Teacher Monthly Fee paid: " << amount << " Total Fee: " << monthly_fee << endl;
        }
};


class Staff : public User {
    private:
        float monthly_fee;

    public:
        Staff() : User(), monthly_fee(0.0) {}
        Staff(int staff_id, string name) : User(staff_id, name), monthly_fee(0.0) {}

        void payFee(float amount) override {
            monthly_fee += amount;
            is_Active = true; 
            cout << "Staff Monthly Fee paid: " << amount << " Total Fee: " << monthly_fee << endl;
        }
};


class Bus {
    private:
        int bus_ID;
        int capacity;
        int current_Capacity;

    public:
        Bus() : bus_ID(0), capacity(0), current_Capacity(0) {}
        Bus(int id, int cap) : bus_ID(id), capacity(cap), current_Capacity(0) {}

        void recordAttendance(int user_id) {
            if (current_Capacity < capacity) {
                cout << "Attendance marked for User ID: " << user_id << endl;
                current_Capacity++;
            } else {
                cout << "MAX CAPACITY REACHED!" << endl;
            }
        }
};


class Route {
    private:
        int route_Id;
        string start_Location;
        string end_Location;
        string stops[10];
        int stops_Count;

    public:
        Route() : route_Id(0), start_Location(""), end_Location(""), stops_Count(0) {}
        Route(int id, string start, string end) : route_Id(id), start_Location(start), end_Location(end), stops_Count(0) {}

        void addStops(string stop) {
            if (stops_Count < 10) {
                stops[stops_Count++] = stop;
                cout << "New Stop Added: " << stop << endl;
            } else {
                cout << "MAX STOPS REACHED!" << endl;
            }
        }

        void removeStops(string stop) {
            for (int i = 0; i < stops_Count; i++) {
                if (stop == stops[i]) {
                    cout << "STOP REMOVED: " << stop << endl;
                    stops_Count--;
                    return;
                }
            }
            cout << "NO STOP FOUND with name: " << stop << endl;
        }

        bool operator==(const Route& other) const {
            return (route_Id == other.route_Id && start_Location == other.start_Location && end_Location == other.end_Location);
        }
};


class TransportationSystem {
    private:
        static const int MAX_USERS = 100;
        static const int MAX_BUSES = 10;
        static const int MAX_ROUTES = 10;
        User* users[MAX_USERS];
        Bus buses[MAX_BUSES];
        Route routes[MAX_ROUTES];
        int userCount;
        int busCount;
        int routeCount;

    public:
        TransportationSystem() : userCount(0), busCount(0), routeCount(0) {}

        void registerStudent(int studentID, string name) {
            if (userCount < MAX_USERS) {
                users[userCount++] = new Student(studentID, name);
                cout << "Student registered: " << name << endl;
            } else {
                cout << "Maximum user limit reached!" << endl;
            }
        }

        void registerTeacher(int teacherID, string name) {
            if (userCount < MAX_USERS) {
                users[userCount++] = new Teacher(teacherID, name);
                cout << "Teacher registered: " << name << endl;
            } else {
                cout << "Maximum user limit reached!" << endl;
            }
        }

        void registerStaff(int staffID, string name) {
            if (userCount < MAX_USERS) {
                users[userCount++] = new Staff(staffID, name);
                cout << "Staff registered: " << name << endl;
            } else {
                cout << "Maximum user limit reached!" << endl;
            }
        }

        void payFee(int userID, float amount) {
            for (int i = 0; i < userCount; i++) {
                if (users[i]->getID() == userID) {
                    users[i]->payFee(amount); 
                    return;
                }
            }
            cout << "User  ID not found!" << endl;
        }

        void addBus(int id, int capacity) {
            if (busCount < MAX_BUSES) {
                buses[busCount++] = Bus(id, capacity);
                cout << "Bus added with ID: " << id << endl;
            } else {
                cout << "Maximum bus limit reached!" << endl;
            }
        }

        void addRoute(int id, string start, string end) {
            if (routeCount < MAX_ROUTES) {
                routes[routeCount++] = Route(id, start, end);
                cout << "Route added with ID: " << id << endl;
            } else {
                cout << "Maximum route limit reached!" << endl;
            }
        }
};

int main() {
    TransportationSystem system;

    system.registerStudent(1, "Alice");
    system.registerTeacher(2, "Mr. Smith");
    system.registerStaff(3, "Ms. Johnson");

    system.payFee(1, 50.0);
    system.payFee(2, 100.0);
    system.payFee(3, 150.0);

    system.addBus(101, 30);
    system.addRoute(201, "Location A", "Location B");

    return 0;
}