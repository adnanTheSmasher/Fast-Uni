#include<iostream>
using namespace std;

class Vehicle
{
	protected:
		string model;
		double rate;
	public:
		Vehicle(string m, double r): model(m), rate(r){};
		
		virtual double getDailyRate() = 0;
		virtual void displayDetails() = 0;
		
};

class Car: public Vehicle
{
	public:
		Car(string m, double r ): Vehicle(m, r){};
		
		double getDailyRate(){	
			return rate;
		}
		void displayDetails(){
			cout<< "Car Model: "<< model << ", Daily Rate: "<< rate; 
		}
};

class Bike: public Vehicle
{
	public:
		Bike(string m, double r): Vehicle(m, r){};
		
		double getDailyRate(){	
			return rate;
		}
		void displayDetails(){
			cout<< "Bike Model: "<< model << ", Daily Rate: "<< rate; 
		}
};

int main()
{
	
    Vehicle* car = new Car("Toyota Corolla", 55.50);
    Vehicle* bike = new Bike("Yamaha FZ", 20.75); 

    
    car->displayDetails();
    cout << "\nDaily Rate: $" << car->getDailyRate() << endl;

    cout << endl;

    bike->displayDetails();
    cout << "\nDaily Rate: $" << bike->getDailyRate() << endl;

    
    delete car;
    delete bike;

    return 0;	
}