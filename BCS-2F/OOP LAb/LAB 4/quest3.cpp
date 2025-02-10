#include<iostream>
using namespace std;

class Account{
	private:
		string accountNumber;
		string accountHolderName;
		double balance;
		
	public:
		Account(){
			accountNumber = "";
			accountHolderName = "";
			balance = 0.0;
		}
		
		Account(string acc_number, string acc_name, double bal){
			accountNumber = acc_number;
			accountHolderName = acc_name;
			balance = bal;
		}
		
		void deposit(double amount){
			if(amount < 0){
				cout<<"\nInvalid Amount....\n";
				return;
			}
			else{
				balance += amount;
				cout<<"\n"<<amount<< " added into your Balance.....";
			}
		}
		
		void withdraw(double amount){
			if (amount > balance){
				cout<< "\ninsufficinet Balance.....\n";
				return;
			}
			else{
				balance -= amount;
				cout<<"\n"<<amount<< " removed from your Balance.....";
			}
		}
		
		void checkBalance(){
			cout<< "\nAvailable Balance: " <<balance;
		}
};

int main(){
	Account acc1;
	Account acc2("100245678950", "Adnan", 500);
	Account acc3("100245678", "Hussain", 1000);
	
	acc1.checkBalance();
	cout<<"\n-----------\n";
	acc2.checkBalance();
	acc2.deposit(500);
	acc2.withdraw(1000);
	acc2.checkBalance();

	cout<<"\n-----------\n";
	acc3.checkBalance();
	acc3.deposit(-1000);

}