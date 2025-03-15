#include <iostream>
#include <string>
using namespace std;

const int MAX_MENU_ITEMS = 10; 
const int MAX_ORDER_ITEMS = 5;  


class MenuItem {
private:
    string foodName;
    double foodPrice;

public:
    MenuItem() : foodName(""), foodPrice(0.0) {}
    MenuItem(const string& name, double price) : foodName(name), foodPrice(price) {}

    string getName() const {
        return foodName;
    }

    double getPrice() const {
        return foodPrice;
    }
};


class Menu {
private:
    MenuItem items[MAX_MENU_ITEMS];
    int itemCount;

public:
    Menu() : itemCount(0) {}

    void addItem(const MenuItem& item) {
        if (itemCount < MAX_MENU_ITEMS) {
            items[itemCount++] = item;
        } else {
            cout << "Menu is full, cannot add more items." << endl;
        }
    }

    void removeItem(const string& name) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i].getName() == name) {
                // Shift items to the left
                for (int j = i; j < itemCount - 1; ++j) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                return;
            }
        }
        cout << "Item not found in the menu." << endl;
    }

    void displayMenu() const {
        cout << "Menu:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i].getName() << " - $" << items[i].getPrice() << endl;
        }
    }

    const MenuItem* getItems() const {
        return items;
    }

    int getItemCount() const {
        return itemCount;
    }
};


class Payment {
private:
    double amount;

public:
    Payment(double amt) : amount(amt) {}

    double getAmount() const {
        return amount;
    }
};


class Order {
private:
    MenuItem orderedItems[MAX_ORDER_ITEMS];
    int itemCount;
    Payment payment;

public:
    Order(const MenuItem* items, int count) : itemCount(count), payment(calculateTotal(items, count)) {
        for (int i = 0; i < count; ++i) {
            orderedItems[i] = items[i];
        }
    }

    Payment calculateTotal(const MenuItem* items, int count) {
        double total = 0.0;
        for (int i = 0; i < count; ++i) {
            total += items[i].getPrice();
        }
        return Payment(total);
    }

    void displayOrder() const {
        cout << "Order Summary:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << orderedItems[i].getName() << " - $" << orderedItems[i].getPrice() << endl;
        }
        cout << "Total Amount: $" << payment.getAmount() << endl;
    }
};


class RestaurantOrderingSystem {
private:
    Menu menu;

public:
    void setMenu(const Menu& m) {
        menu = m;
    }

    void placeOrder(const string itemNames[], int count) {
        MenuItem orderedItems[MAX_ORDER_ITEMS];
        int orderedCount = 0;

        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < menu.getItemCount(); ++j) {
                if (menu.getItems()[j].getName() == itemNames[i]) {
                    orderedItems[orderedCount++] = menu.getItems()[j];
                    break;
                }
            }
        }

        Order order(orderedItems, orderedCount);
        order.displayOrder();
    }
};

int main() {
    
    MenuItem burger("Burger", 5.99);
    MenuItem fries("Fries", 2.49);
    MenuItem soda("Soda", 1.99);

    
    Menu menu;
    menu.addItem(burger);
    menu.addItem(fries);
    menu.addItem(soda);

    
    menu.displayMenu();

    
    RestaurantOrderingSystem restaurant;
    restaurant.setMenu(menu);

    
    string orderItems[] = {"Burger", "Fries"};
    restaurant.placeOrder(orderItems, 2);

    return 0;
}