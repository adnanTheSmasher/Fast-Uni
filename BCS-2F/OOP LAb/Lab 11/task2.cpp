#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

template <typename T>
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int top;

public:
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T element) {
        if (top >= capacity - 1) {
            throw StackOverflowException<T>();
        }
        arr[++top] = element;
    }

    T pop() {
        if (top < 0) {
            throw StackUnderflowException<T>();
        }
        return arr[top--];
    }
};

int main() {
    Stack<int> stack(2);
    
    try {
        stack.push(1);
        stack.push(2);
        stack.push(3); 
    } catch (const StackOverflowException<int>& e) {
        cout << "Pushing to a full stack: " << e.what() << endl;
    }

    try {
        stack.pop();
        stack.pop();
        stack.pop(); 
    } catch (const StackUnderflowException<int>& e) {
        cout << "Popping from an empty stack: " << e.what() << endl;
    }

    return 0;
}