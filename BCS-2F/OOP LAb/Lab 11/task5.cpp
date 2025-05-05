#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
using namespace std;



template <typename T>
class InsufficientFundsException : public runtime_error {
public:
    InsufficientFundsException(T deficit)
        : runtime_error("InsufficientFundsException - Deficit: " + to_string(deficit)) {}
};


template <typename T>
class BankAccount {
private:
    T balance;

public:
    BankAccount(T initial_balance) : balance(initial_balance) {}

    void withdraw(T amount) {
        if (amount > balance) {
            T deficit = amount - balance;
            throw InsufficientFundsException<T>(deficit);
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << fixed << setprecision(2) << balance << endl;
        }
    }

   
    void displayBalance() const {
        cout << "Balance: " << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    try {
        BankAccount<double> account(500.00);  
        account.displayBalance();               
        
        account.withdraw(600.00);              
    } catch (const InsufficientFundsException<double>& e) {
        cout << e.what() << endl;    
    }

    return 0;
}