#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

// Base class
class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    string transactionHistory[10]; 
    int transactionCount; 

public:
    Account(string accNum, string holderName, double initialBalance, string type = "General")
        : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance), accountType(type), transactionCount(0) {}

    virtual void deposit(double amount) {
        balance += amount;
        if (transactionCount < 10) {
            transactionHistory[transactionCount++] = "Deposited: $" + to_string(amount);
        }
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds for withdrawal." << endl;
        } else {
            balance -= amount;
            if (transactionCount < 10) {
                transactionHistory[transactionCount++] = "Withdrew: $" + to_string(amount);
            }
        }
    }

    virtual double calculateInterest() {
        return 0.0; 
    }

    virtual void printStatement() {
        cout << "Account Statement for " << accountHolderName << " (" << accountType << " Account)" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
        cout << "Transaction History:" << endl;
        for (int i = 0; i < transactionCount; i++) {
            cout << transactionHistory[i] << endl;
        }
    }

    virtual void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, string holderName, double initialBalance, double rate, double minBalance)
        : Account(accNum, holderName, initialBalance, "Savings"), interestRate(rate), minimumBalance(minBalance) {}

    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds for withdrawal." << endl;
        } else if (balance - amount < minimumBalance) {
            cout << "Withdrawal would drop balance below minimum required." << endl;
        } else {
            balance -= amount;
            transactionHistory[transactionCount++] = "Withdrew: $" + to_string(amount);
        }
    }

    double calculateInterest() override {
        return balance * (interestRate / 100);
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};


class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, string holderName, double initialBalance, double overdraft)
        : Account(accNum, holderName, initialBalance, "Checking"), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Withdrawal exceeds overdraft limit." << endl;
        } else {
            balance -= amount;
            transactionHistory[transactionCount++] = "Withdrew: $" + to_string(amount);
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Overdraft Limit: $" << fixed << setprecision(2) << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(string accNum, string holderName, double initialBalance, double rate, string maturity)
        : Account(accNum, holderName, initialBalance, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    double calculateInterest() override {
        return balance * (fixedInterestRate / 100);
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};


int main() {

    SavingsAccount savings("SA001", "Alice Johnson", 1000.0, 5.0, 200.0);
    CheckingAccount checking("CA001", "Bob Smith", 500.0, 300.0);
    FixedDepositAccount fixedDeposit("FD001", "Charlie Brown", 2000.0, 6.0, "2025-12-31");

    savings.deposit(200);
    savings.withdraw(100);
    savings.printStatement();
    cout << endl;

    checking.deposit(150);
    checking.withdraw(700);
    checking.printStatement();
    cout << endl;

    fixedDeposit.deposit(500);
    fixedDeposit.printStatement();
    cout << "Interest earned: $" << fixedDeposit.calculateInterest() << endl;

    return 0;
}