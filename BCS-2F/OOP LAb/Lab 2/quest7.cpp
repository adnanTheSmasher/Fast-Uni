#include<iostream>
#include<string.h>
using namespace std;
const int MAX_PRODUCT = 100;
struct Product{
    int product_ID;
    string name;
    float price;
    int quantity;
    string description;
};

struct ProductManagerSystem{
    Product product[MAX_PRODUCT];
    int productCount = 0;
};

void add_Function(struct ProductManagerSystem &pms, int product_id, string name, float price, int quantity, string description){

    if(pms.productCount >= MAX_PRODUCT){
        cout<<"MAX product Reached";
        return;
    }

    for(int i=0; i<pms.productCount; i++){
       if(pms.product[i].product_ID == product_id){
        cout<<"Product with ID " << product_id << " already exists." << endl;
        return;
       } 
    }

    pms.product[pms.productCount] = {product_id, name, price, quantity, description};
    pms.productCount++;
}

void display_information(struct ProductManagerSystem &pms, int product_id){
    bool found = false;
    for(int i=0; i<pms.productCount; i++){
        if(pms.product[i].product_ID == product_id){
            found = true;
            cout << "Product ID: " << pms.product[i].product_ID
                      << ", Name: " << pms.product[i].name
                      << ", Price: $" << pms.product[i].price
                      << ", Quantity: " << pms.product[i].quantity
                      << ", Description: " << pms.product[i].description << endl;
            break;
        }
    }
    if(!found)
        cout<<"Product with ID " << product_id << " not found." << std::endl;
}

void update_Information_func(struct ProductManagerSystem &pms, int product_id, string updated_name = "", float updated_price = 0, int updated_quantity = 0, string updated_description = ""){
    bool found = false;
    for(int i=0; i<pms.productCount; i++){
        if(pms.product[i].product_ID == product_id){
            found = true;
            pms.product[i] = {product_id, updated_name, updated_price, updated_quantity, updated_description};
        }
    }
    
     if(!found)
        cout<<"Product with ID " << product_id << " not found." << endl;
}

void remove_item_from_inventory(struct ProductManagerSystem &pms, int product_id){
    bool found = false;
    for(int i=0; i<pms.productCount; i++){
        if(pms.product[i].product_ID = product_id){
            found = true;
            for(int j=i; j<pms.productCount - 1; j++){
                pms.product[j] = pms.product[j+1];
            }
            pms.productCount--;
            cout << "Product ID " << product_id << " removed successfully." << endl;
        }
    }

    if(!found)
        cout<<"Product with ID " << product_id << " not found." << endl;
}

int main(){
     ProductManagerSystem pms;
    int choice;

    do {
        cout << "\nProduct Management System\n";
        cout << "1. Add Product\n";
        cout<< "2. Display Product\n";
        cout<< "3. Update Product\n";
        cout<< "4. Remove Product\n";
        cout<< "5. Exit\n";
        cout<< "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int product_id;
                string name, description;
                double price;
                int quantity;

                cout<< "Enter Product ID: ";
                cin >> product_id;
                cout<< "Enter Product Name: ";
                cin.ignore(); 
                getline(cin, name);
                cout<< "Enter Product Price: ";
                cin >> price;
                cout<< "Enter Product Quantity: ";
                cin >> quantity;
                cout<< "Enter Product Description: ";
                cin.ignore(); 
                getline(cin, description);

                add_Function(pms, product_id, name, price, quantity, description);
                break;
            }
            case 2: {
                int product_id;
                cout<< "Enter Product ID to display: ";
                cin >> product_id;
                display_information(pms, product_id);
                break;
            }
            case 3: {
                 int product_id;
                string name, description;
                double price;
                int quantity;

                cout<< "Enter Product ID: ";
                cin >> product_id;
                cout<< "Enter Product Name: ";
                cin.ignore(); 
                getline(cin, name);
                cout<< "Enter Product Price: ";
                cin >> price;
                cout<< "Enter Product Quantity: ";
                cin >> quantity;
                cout<< "Enter Product Description: ";
                cin.ignore(); 
                getline(cin, description);

                update_Information_func(pms, product_id, name, price, quantity, description);
                break;
            }
            case 4: {
                int product_id;
                cout<< "Enter Product ID to remove: ";
                cin >> product_id;
                remove_item_from_inventory(pms, product_id);
                break;
            }
            case 5:
                cout<< "Exiting the program." << endl;
                break;
            default:
                cout<< "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}