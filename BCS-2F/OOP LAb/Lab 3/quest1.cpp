#include<iostream>
#include<iomanip>
using namespace std;


class Time{
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		Time():hours(0), minutes(0), seconds(0) {}
		Time(int h, int m, int s):hours(h), minutes(m), seconds(s) {
			if (seconds >= 60) {
            	minutes += seconds / 60;
            	seconds %= 60;
        	}
        	if (minutes >= 60) {
        	    hours += minutes / 60;
            	minutes %= 60;
        	}
		}
		
		void display_time() const{
			cout<< setw(2)<<setfill('0')<<hours<<":"<<
				   setw(2)<<setfill('0')<<minutes<<":"<<
				   setw(2)<<setfill('0')<<seconds<<endl;	
		}
		
		Time add_time(const Time& other){
			return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
		}
		
		void checking_time_values() {
        
    }
};


int main(){
	Time time1(5, 45, 65);
	Time time2(6, 5, 5);
	
	Time time3 = time1.add_time(time2);
	
	time1.display_time();
	time3.display_time();
}