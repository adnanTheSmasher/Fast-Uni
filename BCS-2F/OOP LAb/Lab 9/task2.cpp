#include<iostream>
using namespace std;

class SmartDevices
{
	public:
		virtual void turnOn() = 0;
		virtual void turnOff() = 0;
		virtual void getStatus() = 0;
};

class LightBulb: public SmartDevices
{
	private:
		bool isOn;
		int brightness;
	public:
		LightBulb(bool status, int b): isOn(status), brightness(b){};

		void turnOn(){
			isOn = true;
			cout<< "\nLight Turned ON";
		}
		void turnOff(){
			isOn = false;
			cout<< "\nLight Turned OFF";
		}
		void getStatus(){
			cout<< "\nLight Status: "<< isOn<< ", Brightenss Level: "<< brightness;
		}
};

class Thermostat: public SmartDevices
{
	private:
		bool isOn;
		double temperature;
	public:
		Thermostat(bool status, double t): isOn(status), temperature(t){};
		
		void turnOn(){
			isOn = true;
			cout<< "\nThermostate Activated";
		}
		void turnOff(){
			isOn = false;
			cout<< "\nThermostate Deactivated";
		}
		void getStatus(){
			cout<< "\nThermostate Status: "<< isOn<< ", Temperature Level: "<< temperature;
		}
};

int main()
{	
	SmartDevices* bulb = new LightBulb(false, 75); 
	SmartDevices* thermostat = new Thermostat(false, 22.5);


	bulb->turnOn();
	bulb->getStatus();

	thermostat->turnOn();
	thermostat->getStatus();


	bulb->turnOff();
	bulb->getStatus();

	thermostat->turnOff();
	thermostat->getStatus();

	return 0;  	
}