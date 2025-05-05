#include <iostream>
#include <stdexcept>
#include <type_traits>

class NegativeNumberException : public std::runtime_error {
public:
    NegativeNumberException() : std::runtime_error("NegativeNumberException: Input must be non-negative!") {}
};

class InvalidTypeException : public std::runtime_error {
public:
    InvalidTypeException() : std::runtime_error("InvalidTypeException: Non-numeric type detected!") {}
};

template<typename T>
T sqrt(T num) {
    if constexpr (!std::is_arithmetic<T>::value) {
        throw InvalidTypeException();
    }
    if (num < 0) {
        throw NegativeNumberException();
    }
    return std::sqrt(num); 
}

int main() {
    try {
        std::cout << "sqrt(4): " << sqrt(4) << std::endl; 
        std::cout << "sqrt(-4): " << sqrt(-4) << std::endl;
    } catch (const NegativeNumberException& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        std::cout << "sqrt(\"hello\"): " << sqrt(std::string("hello")) << std::endl; 
    } catch (const InvalidTypeException& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}