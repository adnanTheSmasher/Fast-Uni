#include<iostream>
using namespace std;

class Car{
	public:
		void startEngine(){
			cout<<"Engine started.";
		}
};

int main(){
	Car car;
	car.startEngine();
}