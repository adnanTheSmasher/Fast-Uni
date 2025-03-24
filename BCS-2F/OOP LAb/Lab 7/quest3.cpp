#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;


class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; 

public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() = 0; 
    virtual double convertTo(Currency* targetCurrency) = 0; 
    virtual void displayCurrency() = 0; 

  
    double getExchangeRate() const {
        return exchangeRate;
    }

    
    string getCurrencySymbol() const {
        return currencySymbol;
    }
};


class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$") {}

    double convertToBase() override {
        return amount; 
    }

    double convertTo(Currency* targetCurrency) override {
        return amount * (targetCurrency->getExchangeRate() / this->getExchangeRate());
    }

    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << getCurrencySymbol() << amount << " (" << currencyCode << ")" << endl;
    }
};


class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.85) {} 

    double convertToBase() override {
        return amount / exchangeRate; 
    }

    double convertTo(Currency* targetCurrency) override {
        return (amount / exchangeRate) * targetCurrency->getExchangeRate();
    }

    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << getCurrencySymbol() << amount << " (" << currencyCode << ")" << endl;
    }
};


class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 0.013) {} 

    double convertToBase() override {
        return amount / exchangeRate; 
    }

    double convertTo(Currency* targetCurrency) override {
        return (amount / exchangeRate) * targetCurrency->getExchangeRate();
    }

    void displayCurrency() override {
        cout << fixed << setprecision(2);
        cout << getCurrencySymbol() << amount << " (" << currencyCode << ")" << endl;
    }
};


int main() {
  
    Dollar dollar(100);
    Euro euro(100);
    Rupee rupee(10000);

   
    cout << "Dollar: ";
    dollar.displayCurrency();
    
    cout << "Euro: ";
    euro.displayCurrency();
    
    cout << "Rupee: ";
    rupee.displayCurrency();

  
    double euroToDollar = euro.convertTo(&dollar);
    cout << "100 Euro in Dollar: " << dollar.getCurrencySymbol() << euroToDollar << endl;

    
    double rupeeToEuro = rupee.convertTo(&euro);
    cout << "10000 Rupee in Euro: " << euro.getCurrencySymbol() << rupeeToEuro << endl;

    return 0;
}