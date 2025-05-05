#include<iostream>
#include<exception>
using namespace std;

class InvalidException: public exception
{
    public:
        const char* what() const noexcept override {
        return "InvalidValueException - Age cannot be negative or exceed 120.";
    }
};

void validateAge(int age) {
    if (age < 0 || age > 120) {
        throw InvalidException();
    }
}

int main()
{
    int age;
    std::cout << "Enter age: ";
    std::cin >> age;

    try
    {
        validateAge(age);
        throw InvalidException();
        cout << "All Good";
    }
    catch(InvalidException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}