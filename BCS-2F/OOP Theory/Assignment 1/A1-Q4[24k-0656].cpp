#include<iostream>
#include<string.h>
using namespace std;

class Student
{
    private:
        int student_ID;
        string student_Name;
        float semester_fee;
        bool is_Active;
        bool is_Registered;
  
    public:
        Student() : student_ID(0), student_Name(""), is_Registered(false), semester_fee(0.0), is_Active(false) {};
        Student(int std_id, string name)
        {
            student_ID = std_id;
            student_Name = name;
            semester_fee = 0;
            is_Active = false;
            is_Registered = false;  
        }

        void paySemesterFee(int amount)
        {
            semester_fee += amount;
            if(semester_fee > 100)
            {
               activated() ;
            }
            cout<< "Fee paid " << amount << " Total Fee: " << semester_fee; 
        }
        
        void activated()
        {
            is_Active = true;
            cout<< "\n------------------------\n";
            cout<< "Card Has been Activated for "<< student_ID;
            cout<< "\n------------------------\n";
        }

        void Deactivated()
        {
            is_Active = false;
            cout<< "\n------------------------\n";
            cout<< "Card Has been DeActivated for "<< student_ID;
            cout<< "\n------------------------\n";
        }

        string getName() const
        {
            return student_Name;
        }
        int getID() const
        {
            return student_ID;
        }
        
        bool getIsActive() const
        {
            return is_Active;
        }
        
};

class Bus
{
    private:
        int bus_ID;
        int capacity;
        int current_Capacity;
        string route;

    public:
        Bus(): bus_ID(0), capacity(0), current_Capacity(0), route(""){};
        Bus(int _bus_Id, string _route,int _capacity)
        {
            bus_ID = _bus_Id;
            capacity = _capacity;
            route = _route;
        }

        void recordAttenence(int std_id)
        {
            if(current_Capacity < capacity)
            {
                cout<< "\n------------------------\n";
                cout<< "Attendence Marked for student " << std_id;
                cout<< "\n------------------------\n";
                current_Capacity++;
            }
            else
            {
                cout<< "\n------------------------\n";
                cout<< "MAX CAPACITY REACHED... ";
                cout<< "\n------------------------\n";
            }
        }

        void removeStudent(int std_id)
        {
            cout<< "\n------------------------\n";
            cout<< "Student Removed From Bus " << std_id;
            cout<< "\n------------------------\n";
            current_Capacity--;
        }

        int getBusID() const
        {
            return bus_ID; 
        }
};

class Route
{
    private:
        int route_Id;
        string start_Location;
        string end_Location;
        string stops[10];
        int stops_Count;

    public:
        Route(): route_Id(0), start_Location(""), end_Location(""), stops_Count(0){};
        Route(int _route_ID, string _start_Location, string _end_location)
        {
            route_Id = _route_ID;
            start_Location = _start_Location;
            end_Location = _end_location;
        }

        void addStops(string stop)
        {
            if(stops_Count <= 10)
            {
                stops[stops_Count] = stop;
                cout<< "\n------------------------\n";
                cout<< "New Stop Added To List: " << stop;
                cout<< "\n------------------------\n";
                stops_Count++;
            }
            else
            {
                cout<< "\n------------------------\n";
                cout<< "MAX STOPS REACHED..... ";
                cout<< "\n------------------------\n";
            }
        }

        void removeStops(string stop)
        {
            for(int i=0; i<stops_Count; i++)
            {
                if(stop == stops[i])
                {
                   cout<< "\n------------------------\n";
                    cout<< "STOP REMOVED: "<< stop;
                    cout<< "\n------------------------\n"; 
                    stops_Count--;
                    return;
                }
            }
            cout<< "\n------------------------\n";
            cout<< "NO stop FOUND with name: "<< stop;
            cout<< "\n------------------------\n";
        }

        int getRouteID() const
        {
            return route_Id; 
        }
};


class TransportationSystem {
    private:
        static const int MAX_STUDENTS = 100;
        static const int MAX_BUSES = 10;
        static const int MAX_ROUTES = 10;
        Student students[MAX_STUDENTS];
        Bus buses[MAX_BUSES];
        Route routes[MAX_ROUTES];
        int studentCount;
        int busCount;
        int routeCount;

    public:
        TransportationSystem() : studentCount(0), busCount(0), routeCount(0) {}

        void registerStudent(int studentID, string name)
        {
            if (studentCount < MAX_STUDENTS) 
            {
                students[studentCount++] = Student(studentID, name);
                cout << "Student registered: " << name << endl;
            } 
            else 
            {
                cout << "Maximum student limit reached!" << endl;
            }
    }

    void payFee(int studentID, float amount) 
    {
        for (int i = 0; i < studentCount; i++) 
        {
            if (students[i].getID() == studentID) 
            {
                students[i].paySemesterFee(amount);
                return;
            }
        }
        cout << "Student ID not found!" << endl;
    }

    void assignRoute(int studentID, int routeID) 
    {
        cout << "Route ID: " << routeID << " assigned to student ID: " << studentID << endl;
    }

     void recordAttendance(int studentID, int busID) {
        for (int i = 0; i < busCount; i++) {
            if (buses[i].getBusID() == busID) {
                buses[i].recordAttenence(studentID);
                return;
            }
        }
        cout << "Bus ID not found!" << endl;
    }

    void addBus(int id, string route, int capacity) {
        if (busCount < MAX_BUSES) {
            buses[busCount++] = Bus(id, route, capacity);
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
    system.registerStudent(2, "Bob");
    system.payFee(1, 50.0);
    system.payFee(1, 60.0); 
    system.addBus(101, "Route A", 30);
    system.addRoute(201, "Location A", "Location B");
    system.assignRoute(1, 201);
    system.recordAttendance(1, 101);

    return 0;
}