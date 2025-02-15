#include<iostream>
using namespace std;

class Account{
	private:
		string accountNumber;
		string ownerName;
		double initialBalance;
		
	public:
		Account(){
			accountNumber = "";
			ownerName = "";
			initialBalance = 0.0;
		}
		
		Account(string acc_number, string acc_name, double bal){
			accountNumber = acc_number;
			ownerName = acc_name;
			initialBalance = bal;
		}
		
		void deposit(double amount){
			if(amount < 0){
				cout<<"\nInvalid Amount....\n";
			}
			else{
				initialBalance += amount;
				cout<<"\n"<<amount<< " added into your Baalnce....";
			}
		}
        void withdraw(double amount)
        {
            if(amount < 0){
				cout<<"\nInvalid Amount....\n";
			}
			else{
				initialBalance -= amount;
				cout<<"\n"<<amount<< " removed from your Balance.....";
			}
        }
		void CheckBalance(){
            cout<< "\nAccount Number: " <<accountNumber;
            cout<< "\nAccount Holder Name: " <<ownerName;
			cout<< "\nAvailable Balance: " <<initialBalance;
		}
};

int main(){
	Account acc1;
	Account acc2("100245678950", "Adnan", 500);
	Account acc3("100245678", "Hussain", 1000);
	
	acc1.CheckBalance();
	cout<<"\n-----------\n";
	acc2.CheckBalance();
	acc2.deposit(500);
	acc2.withdraw(1000);
	acc2.CheckBalance();

	cout<<"\n-----------\n";
	acc3.CheckBalance();
	acc3.deposit(-1000);

}