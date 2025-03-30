#include <iostream>
#include <string>
using namespace std;

// Base class
class Product {
protected:
    string productID;
    double price;

public:
    Product(string id, double p) : productID(id), price(p) {}

    virtual double calculatePrice() = 0; 

    virtual void applyDiscount(double amount) = 0; 

    string getProductID(){return productID;}
};


class Electronics : public Product {
public:
    Electronics(string id, double p) : Product(id, p) {}

    double calculatePrice() override {
        return price + (price * 0.15); 
    }

    void applyDiscount(double amount) override {
        price -= amount; 
        cout << "Applied a discount of $" << amount << " on Electronics." << endl;
    }
};


class Clothing : public Product {
public:
    Clothing(string id, double p) : Product(id, p) {}

    double calculatePrice() override {
        return price + (price * 0.05); 
    }

    void applyDiscount(double amount) override {
        price -= amount;
        cout << "Applied a discount of $" << amount << " on Clothing." << endl;
    }
};


class ShoppingCart {
private:
    Product* products[10]; 
    int productCount;

public:
    ShoppingCart() : productCount(0) {}

    void addProduct(Product* product) {
        if (productCount < 10) {
            products[productCount++] = product;
            cout << "Added product with ID: " << product->getProductID() << " to the cart." << endl;
        } else {
            cout << "Cart is full! Cannot add more products." << endl;
        }
    }

  
    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart newCart;
        for (int i = 0; i < productCount; i++) {
            newCart.addProduct(products[i]);
        }
        for (int i = 0; i < other.productCount; i++) {
            newCart.addProduct(other.products[i]);
        }
        return newCart;
    }

   
    void operator-(const string& productID) {
        for (int i = 0; i < productCount; i++) {
            if (products[i]->getProductID() == productID) {
                cout << "Removed product with ID: " << productID << " from the cart." << endl;
                for (int j = i; j < productCount - 1; j++) {
                    products[j] = products[j + 1]; // Shift products left
                }
                productCount--;
                return;
            }
        }
        cout << "Product with ID: " << productID << " not found in the cart." << endl;
    }

   
    void operator*(double discountPercentage) {
        for (int i = 0; i < productCount; i++) {
            double discountAmount = products[i]->calculatePrice() * (discountPercentage / 100);
            products[i]->applyDiscount(discountAmount);
        }
    }

    double operator/(int users) {
        double total = 0;
        for (int i = 0; i < productCount; i++) {
            total += products[i]->calculatePrice();
        }
        return total / users;
    }

    double calculateTotal() {
        double total = 0;
        for (int i = 0; i < productCount; i++) {
            total += products[i]->calculatePrice();
        }
        return total;
    }

    void displayCart() {
        cout << "Shopping Cart Contents:" << endl;
        for (int i = 0; i < productCount; i++) {
            cout << "Product ID: " << products[i]->getProductID() << ", Price: $" << products[i]->calculatePrice() << endl;
        }
    }
};

int main() {
   
    Electronics laptop("E001", 1000);
    Clothing shirt("C001", 50);

   
    ShoppingCart cart1;
    ShoppingCart cart2;

    cart1.addProduct(&laptop);
    cart1.addProduct(&shirt);

 
    cart1.displayCart();


    laptop.applyDiscount(100); 
    cout << "Total after discount on laptop: $" << laptop.calculatePrice() << endl;

    Electronics phone("E002", 800);
    cart2.addProduct(&phone);

    
    ShoppingCart mergedCart = cart1 + cart2;
    mergedCart.displayCart();

    
    mergedCart * 10;

 
    cout << "Total price after bulk discount: $" << mergedCart.calculateTotal() << endl;


    double splitTotal = mergedCart / 3;
    cout << "Total price per user: $" << splitTotal << endl;

    return 0;
}