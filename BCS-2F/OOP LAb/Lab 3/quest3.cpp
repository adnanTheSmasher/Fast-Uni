#include<iostream>
using namespace std;

class serialNumberholder{
	private:
		static int counter;
		int serialnumber;
	public:
		serialNumberholder(){
			counter++;
			serialnumber = counter;
		}
		
		void display_Serial_Number(){
			cout<<"I am object number: "<< serialnumber <<endl;
		}
};

int serialNumberholder::counter = 0;

int main(){
	serialNumberholder obj1;
	serialNumberholder obj2;
	serialNumberholder obj3;
	
	obj3.display_Serial_Number();
	obj1.display_Serial_Number();
	obj2.display_Serial_Number();
	
}