#include<iostream>
#include<string.h>
using namespace std;

class BankAcount
{
	private:
		string accountNumber;
		string accountHolderName;
		double balance;

	public:
		BankAcount() {};
		BankAcount(string accNum, string accName, double bal) : accountNumber(accNum), accountHolderName(accName), balance(bal) {};

		void deposit(double amount)
		{
			balance += amount;
		}

		void withdraw(double amount)
		{
			if (amount > balance)
				cout << "Not enought Balance....";
			else
				balance -= amount;
		}

		void display()
		{
			cout << "\n-------------Account Holder Details-------------\n";
			cout << "Account Holder Name: " << accountHolderName << endl;
			cout << "Account Number: " << accountNumber << endl;
			cout << "Balance: " << balance << endl;
		}


};

int main()
{
	BankAcount accounts[3];
	accounts[0] = BankAcount("01234", "Adnan", 25000);
	accounts[1] = BankAcount("56789", "James", 5000);
	accounts[2] = BankAcount("52873", "Lilith", 250);
	for (int i = 0; i <= 2; i++)
	{
		accounts[i].display();
		accounts[i].deposit(500);
		accounts[i].display();
		accounts[i].withdraw(200);
		accounts[i].display();
	}
}