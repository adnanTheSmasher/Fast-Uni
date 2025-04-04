#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    static int activeDeliveries; 
    double speed; 
    double capacity; 
    double energyEfficiency; 

public:
    Vehicle(string id, double spd, double cap, double eff) : vehicleID(id), speed(spd), capacity(cap), energyEfficiency(eff) {
        activeDeliveries++;
    }

    virtual void calculateRoute() = 0; 
    virtual void estimatedDeliveryTime() = 0; 

    static int getActiveDeliveries() {
        return activeDeliveries;
    }


    bool operator==(const Vehicle& other) {
        return (this->speed == other.speed && this->capacity == other.capacity && this->energyEfficiency == other.energyEfficiency);
    }

    friend void resolveConflict(Vehicle* v1, Vehicle* v2);

    virtual ~Vehicle() {
        activeDeliveries--;
    }
};

int Vehicle::activeDeliveries = 0;


class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id) : Vehicle(id, 100.0, 5.0, 0.9) {} 

    void calculateRoute() override {
        cout << "Calculating aerial route for RamzanDrone " << vehicleID << endl;
    }

    void estimatedDeliveryTime() override {
        cout << "Estimating delivery time for RamzanDrone " << vehicleID << endl;
    }

    void command(string action, string packageID) {
        cout << "RamzanDrone " << vehicleID << " executing command: " << action << " for package " << packageID << endl;
    }

    void command(string action, string packageID, string urgencyLevel) {
        if (urgencyLevel == "Urgent") {
            cout << "RamzanDrone " << vehicleID << " activating high-speed mode for urgent delivery of package " << packageID << endl;
        } else {
            command(action, packageID); 
        }
    }
};


class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id) : Vehicle(id, 80.0, 20.0, 0.8) {} 
    void calculateRoute() override {
        cout << "Verifying historical consistency for RamzanTimeShip " << vehicleID << endl;
    }

    void estimatedDeliveryTime() override {
        cout << "Estimating delivery time for RamzanTimeShip " << vehicleID << endl;
    }

    void command(string action, string packageID) {
        cout << "RamzanTimeShip " << vehicleID << " executing command: " << action << " for package " << packageID << endl;
    }

    void command(string action, string packageID, string urgencyLevel) {
        if (urgencyLevel == "Urgent") {
            cout << "RamzanTimeShip " << vehicleID << " validating historical accuracy for urgent delivery of package " << packageID << endl;
        } else {
            command(action, packageID); 
        }
    }
};


class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id) : Vehicle(id, 120.0, 50.0, 0.95) {}

    void calculateRoute() override {
        cout << "Navigating underground tunnel for RamzanHyperPod " << vehicleID << endl;
    }

    void estimatedDeliveryTime() override {
        cout << "Estimating delivery time for RamzanHyperPod " << vehicleID << endl;
    }

    void command(string action, string packageID) {
        cout << "RamzanHyperPod " << vehicleID << " executing command: " << action << " for package " << packageID << endl;
    }

    void command(string action, string packageID, string urgencyLevel) {
        cout << "RamzanHyperPod " << vehicleID << " executing command: " << action << " for package " << packageID << " with urgency " << urgencyLevel << endl;
    }
};


void resolveConflict(Vehicle* v1, Vehicle* v2) {
    cout << "Resolving conflict between vehicles " << v1->vehicleID << " and " << v2->vehicleID << endl;

    if (v1->energyEfficiency > v2->energyEfficiency) {
        cout << "Vehicle " << v1->vehicleID << " is prioritized due to higher efficiency." << endl;
    } else if (v1->energyEfficiency < v2->energyEfficiency) {
        cout << "Vehicle " << v2->vehicleID << " is prioritized due to higher efficiency." << endl;
    } else {
        cout << "Both vehicles have equal efficiency. No priority assigned." << endl;
    }
}


int main() { 
    RamzanDrone drone1("Drone1");
    RamzanTimeShip timeShip1("TimeShip1");
    RamzanHyperPod hyperPod1("HyperPod1");

    drone1.calculateRoute();
    drone1.estimatedDeliveryTime();
    drone1.command("Deliver", "Package1");
    drone1.command("Deliver", "Package1", "Urgent");

    timeShip1.calculateRoute();
    timeShip1.estimatedDeliveryTime();
    timeShip1.command("Deliver", "Package2");
    timeShip1.command("Deliver", "Package2", "Urgent");

    hyperPod1.calculateRoute();
    hyperPod1.estimatedDeliveryTime();
    hyperPod1.command("Deliver", "Package3");
    hyperPod1.command("Deliver", "Package3", "Urgent");

    
    resolveConflict(&drone1, &timeShip1);

    cout << "Total active deliveries: " << Vehicle::getActiveDeliveries() << endl;

    return 0;
}