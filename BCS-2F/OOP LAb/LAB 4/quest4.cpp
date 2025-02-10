#include<iostream>
using namespace std;

class Car{
	private:
		int carID;
		string model;
		int year;
  		bool isRented;
  		
  	public:
  		Car(){
  			isRented = false;
		  }
  		
  		Car(int c_id, string c_model, int c_year, bool c_rented){
  			carID = c_id;
  			model = c_model;
  			year = c_year;
  			isRented = c_rented;
		  }
		  
		void rentCar(){
			isRented = true;
		}
		void returnCar(){
			isRented = false;
		}
		bool isVintage(){
			if(year < 2000){
				return true;
			}
		}
		
		bool getIsrented(){
			return isRented;
		}
  		
};


int main(){
	Car car1; 
    Car car2(2, "Honda Accord", 2005, true);
    Car car3(3, "Ford Mustang", 1967, false);

    cout << "\n------------------\n";
    car2.rentCar(); 
    cout << "Car 2 rented: " << (car2.getIsrented() ? "Yes" : "No") << endl;
    car2.returnCar();
    cout << "Car 2 rented after return: " << (car2.getIsrented() ? "Yes" : "No") << endl;
    cout << "Car 2 is vintage: " << (car2.isVintage() ? "Yes" : "No") << endl;

    cout << "\n------------------\n";
    car3.rentCar(); 
    cout << "Car 3 rented: " << (car3.getIsrented() ? "Yes" : "No") << endl;
    car3.returnCar(); 
    cout << "Car 3 rented after return: " << (car3.getIsrented() ? "Yes" : "No") << endl;
    cout << "Car 3 is vintage: " << (car3.isVintage() ? "Yes" : "No") << endl;

    return 0;

    
    
    
}