#include<iostream>
using namespace std;

class Smartphone{
	string Company;
	string Model;
	string Display_resolution;
	float RAM;
	float ROM;
	float storage;
	
	public:
		
	string getCompany() const {
        return Company;
    }

    string getModel() const {
        return Model;
    }

    string getDisplayResolution() const {
        return Display_resolution;
    }

    int getRAM() const {
        return RAM;
    }

    int getROM() const {
        return ROM;
    }

    int getStorage() const {
        return storage;
    }

    // Setter methods
    void setCompany(const string& comp) {
        Company = comp;
    }

    void setModel(const string& mod) {
        Model = mod;
    }

    void setDisplayResolution(const string& res) {
        Display_resolution = res;
    }

    void setRAM(int r) {
        RAM = r;
    }

    void setROM(int ro) {
        ROM = ro;
    }

    void setStorage(int st) {
        storage = st;
    }

    void makePhoneCall(const string& number) {
        cout << "Calling " << number << " from " << Model << "...\n";
    }

    void sendMessage(const string& number, const string& message) {
        cout << "Sending message to " << number << ": " << message << "\n";
    }

    void connectToWiFi(const string& network) {
        cout << "Connecting to WiFi network: " << network << "...\n";
    }

    void browseInternet(const string& url) {
        cout << "Browsing the internet: " << url << "...\n";
    }
};
		

int main(){
	
}