#include<iostream>
#include<iomanip>
using namespace std;


class Angle{
    private:
        int degrees;
        float minutes;
        char direction;

    public:
        Angle(int deg, float min, char direct): degrees(deg), minutes(min), direction(direct){};

        void inputAngles(){
            cout<< "Enter Degrees: ";
            cin >> degrees;
            cout<< "Enter minutes: ";
            cin >> minutes;
            cout<< "Enter direction: ";
            cin >> direction;
        }

        const string degree_symbol = "°";

        void displayAngles(){
            cout<< degrees<< degree_symbol <<fixed<<setprecision(1)<< minutes<< "' " << direction<<endl;
        }
};

int main(){
    Angle angle(58, 5.8, 'N');

    angle.displayAngles();

    cout << "\n\n";
    char choice;

    do {
        angle.inputAngles();
        angle.displayAngles();
        
        cout<< "Still want to enter Angles (y or n): ";
        cin>> choice;
    }while(choice != 'n');

}