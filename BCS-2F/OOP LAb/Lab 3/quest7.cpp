#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class StationeryShop {
private:
    static const int MAX_ITEMS = 100; 
    string items[MAX_ITEMS];     
    double prices[MAX_ITEMS];         
    int itemCount;                    

public:
    StationeryShop() : itemCount(0) {}

   
    void addItem(const string& item, double price) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item added successfully!" << endl;
        } else {
            cout << "Cannot add more items, maximum limit reached!" << endl;
        }
    }

   
    void fetchItems() const {
        cout << "Items available in the shop:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << (i + 1) << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    
    void editPrice(int index, double newPrice) {
        if (index < 1 || index > itemCount) {
            cout << "Invalid item number!" << endl;
            return;
        }
        prices[index - 1] = newPrice;
        cout << "Price updated successfully!" << endl;
    }

   
    void viewItemsAndPrices() const {
        cout << "Items and their prices:\n";
        for (int i = 0; i < itemCount; ++i) {
            cout << items[i] << ": $" << fixed << setprecision(2) << prices[i] << endl;
        }
    }

   
    void createReceipt() const {
        cout << "\n--- Receipt ---\n";
        double total = 0.0;
        string itemName;
        int quantity;

        while (true) {
            cout << "Enter item name (or 'done' to finish): ";
            cin >> itemName;

            if (itemName == "done") {
                break;
            }

            bool found = false;
            for (int i = 0; i < itemCount; ++i) {
                if (items[i] == itemName) {
                    found = true;
                    cout << "Enter quantity for " << itemName << ": ";
                    cin >> quantity;

                    double itemTotal = prices[i] * quantity;
                    total += itemTotal;

                    cout << quantity << " x " << itemName << " = $" << fixed << setprecision(2) << itemTotal << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found!" << endl;
            }
        }

        cout << "Total Amount: $" << fixed << setprecision(2) << total << endl;
        cout << "Thank you for shopping with us!\n";
    }
};

int main() {
    StationeryShop shop;
    int choice;

    do {
        cout << "\n--- Stationery Shop Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Fetch Items\n";
        cout << "3. Edit Price\n";
        cout << "4. View All Items and Prices\n";
        cout << "5. Create Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                double price;
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter item price: ";
                cin >> price;
                shop.addItem(item, price);
                break;
            }
            case 2:
                shop.fetchItems();
                break;
            case 3: {
                int index;
                double newPrice;
                shop.fetchItems();
                cout << "Enter item number to edit price: ";
                cin >> index;
                cout << "Enter new price: ";
                cin >> newPrice;
                shop.editPrice(index, newPrice);
                break;
            }
            case 4:
                shop.viewItemsAndPrices();
                break;
            case 5:
                shop.createReceipt();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}