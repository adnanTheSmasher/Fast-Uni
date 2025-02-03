#include<iostream>
#include<conio.h>
using namespace std;

class tolbooth{
	private:
		unsigned int totalCars;
		double totalAmount;
		
	public:
		tolbooth(unsigned int c = 0, double a = 0): totalCars(c), totalAmount(a){}
		
		void payingCars(){
			totalCars++;
			totalAmount += 0.50;
		}
		
		void noPayCars(){
			totalCars++;
		}
		
		void display_totals() const{
			cout<<"Total Number of cars Passed: "<<totalCars<<endl;
			cout<<"Total Number of Amount Collected: $"<<totalAmount;
		}
};


int main(){
	
	tolbooth booth;
	
	cout<<"Press P for Cars which Pay.....\nPress N for cars which do not pay.....\n";
	
	while(true){
		char ch = _getch();
		
		if(ch == 27){
			booth.display_totals();
			break;
		}
		
		else if(ch == 'P' || ch == 'p'){
			cout<<"You Pressed P..... Updated\n";
			booth.payingCars();
		}
		
		else if(ch == 'N' || ch == 'n'){
			cout<<"You Pressed N..... Updated\n";
			booth.noPayCars();
		}
		
		else{
			cout<<"Wront Input Press again.....\n";
		}
	}
	
	
	
}