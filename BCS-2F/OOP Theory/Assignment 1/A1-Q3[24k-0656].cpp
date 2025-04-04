#include<iostream>
#include<string.h>
using namespace std;
class User
{
    private:
        string user_Name;
        int age;
        string licence_Type;
        int contact_Info;
        int user_ID;

    public:
        User(string _name, int _age, string _license, int _contact, int _user_ID)
        {
            user_Name = _name;
            age = _age;
            licence_Type = _license;
            contact_Info = _contact;
            user_ID = _user_ID;
        }

        void update_user_info(string _name, int _age, string _license, int _contact, int _user_ID)
        {
            user_Name = _name;
            age = _age;
            licence_Type = _license;
            contact_Info = _contact;
            user_ID = _user_ID;
        }

        string getName()
        {
            return user_Name;
        }

        int getUserID()
        {
            return user_ID;
        }

        string getLicence()
        {
            return licence_Type;
        }
};

class Vehicle
{
    private:
        string model_name;
        string eligibility;
        int rental_Price_Per_Day;
    public:
        Vehicle(string _model, string _eligibility, int _rental)
        {
            model_name = _model;
            eligibility = _eligibility;
            rental_Price_Per_Day = _rental;
        }

        string getModelName()
        {
            return model_name;
        }
        string getEligibility()
        {
            return eligibility;
        }
        int getRentalPrice()
        {
            return rental_Price_Per_Day;
        }
};

class RentalSystem
{
    private:
        User** users;
        Vehicle** vehicles;
        int MAX_USERS = 10;
        int MAX_VEHICLES = 10;
        int user_count;
        int vehicle_count;

    public:
        RentalSystem()
        {
            users = new User*[MAX_USERS];
            vehicles = new Vehicle*[MAX_VEHICLES];
            user_count = 0;
            vehicle_count = 0;
        }

        void registerUser(string name, int age, string license, int contact, int user_ID)
        {
            if(user_count < MAX_USERS)
            {
                users[user_count] = new User(name, age, license, contact, user_ID);
                cout<< "\n------------------------\n";
                cout<< "New User Created.....";
                cout<< "\n------------------------\n";
                user_count++;
            }
            else
            {
                cout<< "\n------------------------\n";
                cout<< "MAX USER LIMIT REACHED.....";
                cout<< "\n------------------------\n";
            }
        }

        void updateUser(string new_name, int new_age, string new_license, int new_contact, int old_user_ID)
        {
            for(int i=0; i<user_count; i++)
            {
                if(users[i]->getUserID() == old_user_ID)
                {
                    users[i]->update_user_info(new_name ,new_age ,new_license, new_contact, old_user_ID);
                    cout<< "\n------------------------\n";
                    cout<< "User Profile Updated.....";
                    cout<< "\n------------------------\n";
                    return;
                }
            }

            cout<< "\n------------------------\n";
            cout<< "User with ID "<< old_user_ID<< " not FOUND.....";
            cout<< "\n------------------------\n";
        }

        void registerVehicle(string model, string eligibility, int rental)
        {
            if(vehicle_count < MAX_VEHICLES)
            {
                vehicles[vehicle_count] = new Vehicle(model, eligibility, rental);
                cout<< "\n------------------------\n";
                cout<< "New Vehicle Added.....";
                cout<< "\n------------------------\n";
                vehicle_count++;
            }
            else
            {
                cout<< "\n------------------------\n";
                cout<< "MAX VEHICLE LIMIT REACHED.....";
                cout<< "\n------------------------\n";
            }
        }

        void displayVehicles()
        {
            cout << "Available Vehicles:" << endl;
            for (int i = 0; i < vehicle_count; i++) 
            {
                cout << "Model: " << vehicles[i]->getModelName() 
                     << ", Rental Price: $" << vehicles[i]->getRentalPrice() 
                     << ", Eligibility: " << vehicles[i]->getEligibility() << endl;
            }
        }
        void rentingVehicle(int user_ID, string model_name)
        {
            User* user = nullptr;
            for(int i=0; i<user_count; i++)
            {
                if(users[i]->getUserID() == user_ID)   
                {
                    user = users[i];
                    break;
                } 
            }
            if(user == nullptr)
            {
                cout << "User  not found!" << endl;
                return;
            }

            for(int i=0; i<vehicle_count; i++)
            {
                if( (user->getLicence() == vehicles[i]->getEligibility()) || (user->getLicence() == "Intermediate" && vehicles[i]->getEligibility() != "Learner"))
                {
                    cout << "Rental successful! You have rented: " << vehicles[i]->getModelName() 
                         << " for $" << vehicles[i]->getRentalPrice() << " per day." << endl;
                    return;
                }
                else
                {
                    cout << "You are not eligible to rent this vehicle." << endl;
                    return;
                }
            }
            cout << "Vehicle not found!" << endl;

        }

        ~RentalSystem()
        {
            for(int i=0; i<user_count; i++)
            {
                delete users[i];
            }
            for(int i=0; i<vehicle_count; i++)
            {
                delete vehicles[i];
            }

            delete[] users;
            delete[] vehicles;
        }
};

int main() 
{
    RentalSystem system;

    
    system.registerUser ("Alice", 25, "Full", 123456, 1);
    system.registerUser ("Bob", 20, "Learner", 987654, 2);

    
    system.registerVehicle("Toyota Corolla", "Full", 30.0);
    system.registerVehicle("Honda Civic", "Intermediate", 25.0);
    system.registerVehicle("Ford Fiesta", "Learner", 20.0);

    system.displayVehicles();

    system.rentingVehicle(1, "Toyota Corolla");
    system.rentingVehicle(2, "Honda Civic");
    system.rentingVehicle(2, "Ford Fiesta");

    
    system.updateUser ("Alice Smith", 26, "Intermediate", 123456, 1);

    system.displayVehicles();


    system.rentingVehicle(1, "Honda Civic");

    return 0;
}