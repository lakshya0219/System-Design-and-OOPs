// The virtual keyword is a fundamental feature in C++ that enables runtime polymorphism (dynamic binding).
//  It allows derived classes to override methods from base classes, and ensures that the correct function is 
//  called based on the actual object type, not the pointer/reference type.

// Key Concepts
// Dynamic Binding: Function calls are resolved at runtime based on object type

// Function Overriding: Derived classes can provide their own implementation

// Polymorphic Behavior: Same interface, different implementations

#include <iostream>
using namespace std;

class Animal {
public:
    // Virtual function - can be overridden
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
    
    // Non-virtual function
    void eat() {
        cout << "Animal eats" << endl;
    }
};

class Dog : public Animal {
public:
    // Override virtual function
    void makeSound() override {  // 'override' keyword (C++11) is optional but recommended
        cout << "Dog barks: Woof! Woof!" << endl;
    }
    
    // This hides the base class eat(), doesn't override it
    void eat() {
        cout << "Dog eats bones" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
};

int main() {
    Animal* ptr1 = new Dog();
    Animal* ptr2 = new Cat();
    Animal* ptr3 = new Animal();
    
    // Virtual function - calls based on actual object type
    cout << "=== Virtual Function Calls ===" << endl;
    ptr1->makeSound();  // Output: Dog barks: Woof! Woof!
    ptr2->makeSound();  // Output: Cat meows: Meow! Meow!
    ptr3->makeSound();  // Output: Animal makes a sound
    
    // Non-virtual function - calls based on pointer type
    cout << "\n=== Non-Virtual Function Calls ===" << endl;
    ptr1->eat();  // Output: Animal eats (not Dog eats!)
    ptr2->eat();  // Output: Animal eats
    ptr3->eat();  // Output: Animal eats
    
    // To call Dog's eat(), we need Dog pointer
    Dog* dogPtr = dynamic_cast<Dog*>(ptr1);
    if (dogPtr) {
        dogPtr->eat();  // Output: Dog eats bones
    }
    
    delete ptr1;
    delete ptr2;
    delete ptr3;
    
    return 0;
}