#include<iostream>
using namespace std;

class PaymentMethod
{
    public:
        virtual bool processPayment(double amount) = 0;
};

class CreditCard: public PaymentMethod
{
    private:
        string cardNumber;
    public:
        CreditCard(string c): cardNumber(c){};
        bool processPayment(double amount) override {
        if (amount > 0) {
            std::cout << "Processing credit card payment of $" << amount << " using card number: " << cardNumber << std::endl;
            return true;
        } else {
            std::cout << "Invalid payment amount for credit card." << std::endl;
            return false;
        }
    }
};

class DigitalWallet: public PaymentMethod
{
    private:
        double balance;
    public:
        DigitalWallet(double b): balance(b){};
        bool processPayment(double amount) override {
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                std::cout << "Processing digital wallet payment of $" << amount << ". Remaining balance: $" << balance << std::endl;
                return true; 
            } else {
                std::cout << "Insufficient balance or invalid payment amount for digital wallet." << std::endl;
                return false;
            }
    }
};

int main() {
    CreditCard myCard("1234-5678-9012-3456");
    DigitalWallet myWallet(100.0); 


    double paymentAmount1 = 50.0;
    double paymentAmount2 = 150.0; 

    if (myCard.processPayment(paymentAmount1)) {
        std::cout << "Credit card payment successful." << std::endl;
    } else {
        std::cout << "Credit card payment failed." << std::endl;
    }

    if (myWallet.processPayment(paymentAmount1)) {
        std::cout << "Digital wallet payment successful." << std::endl;
    } else {
        std::cout << "Digital wallet payment failed." << std::endl;
    }

    if (myWallet.processPayment(paymentAmount2)) {
        std::cout << "Digital wallet payment successful." << std::endl;
    } else {
        std::cout << "Digital wallet payment failed." << std::endl;
    }

    return 0;
}
