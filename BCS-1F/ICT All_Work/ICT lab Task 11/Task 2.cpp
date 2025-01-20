#include<iostream>
using namespace std;

class Animal{
	public:
		void makeSound(){
			cout<<"Animal Sound."<<endl;
		}
};

class Dog:public Animal{
	public:
		void makeSound(){
			cout<<"Wooof!"<<endl;
		}
};

int main(){
	Animal animal;
	Dog dog;
	
	dog.makeSound();
	
}