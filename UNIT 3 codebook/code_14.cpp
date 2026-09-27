#include <iostream>

using namespace std;

class Base {
public:
  virtual void display() const { cout << "Base object\n"; }
  virtual ~Base() = default;
};

class Derived : public Base {
public:
  void display() const override { cout << "Derived object\n"; }
};

// Slices object (only Base part is copied)
void displayByValue(Base object) { object.display(); }

// Reference preserves derived object
void displayByReference(const Base &object) { object.display(); }

// Function using const Base* pointer
void displayByPointer(const Base *object) {
  object->display(); // Pointer also avoids slicing and preserves polymorphism
}

int main() {
  Derived derived;

  cout << "Passing by value: ";
  displayByValue(derived);

  cout << "Passing by reference: ";
  displayByReference(derived);

  // Pointer function call
  cout << "Passing by pointer: ";
  displayByPointer(&derived);

  return 0;
}