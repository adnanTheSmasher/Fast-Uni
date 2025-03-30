#include <iostream>
#include <string>
using namespace std;


class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    virtual double calculateInterest() = 0;


    double operator+(const BankAccount& other) {
        return this->balance + other.balance;
    }

   
    double operator-(double amount) {
        return this->balance - amount;
    }

    double operator*(double interestRate) {
        return this->balance * interestRate;
    }

   
    double operator/(int installments) {
        return this->balance / installments;
    }

   
    virtual void deposit(double amount) = 0;

   
    virtual void withdraw(double amount) = 0;

   
    void displayBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }
};


class SavingsAccount : public BankAccount {
public:
    SavingsAccount(string accNum, double initialBalance) : BankAccount(accNum, initialBalance) {}

    double calculateInterest() override {
        return balance * 0.05; 
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " to Savings Account." << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < 500) {
            cout << "Withdrawal denied! Minimum balance of $500 must be maintained." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Savings Account." << endl;
        }
    }
};


class CurrentAccount : public BankAccount {
public:
    CurrentAccount(string accNum, double initialBalance) : BankAccount(accNum, initialBalance) {}

    double calculateInterest() override {
        return 0; 
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited $" << amount << " to Current Account." << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount < -1000) {
            cout << "Withdrawal denied! Overdraft limit of $1000 exceeded." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Current Account." << endl;
        }
    }
};

int main() {
    
    SavingsAccount savings("SA123", 1000);
    CurrentAccount current("CA456", 500);

   
    savings.displayBalance();
    current.displayBalance();

    
    savings.deposit(200);
    current.deposit(300);

    
    savings.displayBalance();
    current.displayBalance();

    
    savings.withdraw(600); 
    current.withdraw(1200); 
    savings.withdraw(700); 
    current.withdraw(2000); 

    
    savings.displayBalance();
    current.displayBalance();

    cout << "Interest on Savings Account: $" << savings.calculateInterest() << endl;
    cout << "Interest on Current Account: $" << current.calculateInterest() << endl;

    
    double totalBalance = savings + current;
    cout << "Total Balance (Savings + Current): $" << totalBalance << endl;

    double newBalance = current - 100; 
    cout << "New Balance after withdrawal: $" << newBalance << endl;

    double interestApplied = savings * 0.05; 
    cout << "Interest applied on Savings Account: $" << interestApplied << endl;

    double installment = current / 5; 
    cout << "Equal installment payments from Current Account: $" << installment << endl;

    return 0;
}