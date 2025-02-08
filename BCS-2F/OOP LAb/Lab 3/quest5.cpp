#include<iostream>
#include<iomanip>
using namespace std;

class Calender{
    private:
        string months[12][31];
        int currentYear;

    public:
        Calender(int year): currentYear(year){};

        void addTask(string taskDetail, int month, int day)
        {
            if(month<1 || month>12 || day<1 || day>31)
            {
               cout<<"Invalid Date....";
               return;
            }
            if((month==2 && day>28) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
            {
                cout<<"Invalid Date for the day....";
                return;
            }
            
            months[month - 1][day-1] = taskDetail;
        }

        void RemoveTask(int month, int day)
        {
            if(month<1 || month>12 || day<1 || day>31)
            {
               cout<<"Invalid Date....";
               return;
            }
            if((month==2 && day>28) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30))
            {
                cout<<"Invalid Date for the day....";
                return;
            }
            
            months[month - 1][day-1] = "";
        }

        void displayTasks(){
            for (int month = 0; month < 12; ++month) {
                for (int day = 0; day < 31; ++day) {
                    if (!months[month][day].empty()) {
                        cout << "Month " << (month + 1) << ", Day " << (day + 1) << ": " << months[month][day] << endl;
                    }
                }
            }
        }

};


int main(){
    Calender cal(2025);
    cal.addTask("Play VolleyBall", 2, 15);
    cal.addTask("Play ThrowBall", 3, 15);
    cal.addTask("Play Cricket", 2, 17);
    cal.addTask("Play Tennis", 4, 20);
    cal.addTask("Go to Movies", 6, 1);
    cal.addTask("Go to Gym", 12, 12);

    cal.displayTasks();
    cal.RemoveTask(6,1);
    cal.displayTasks();


}