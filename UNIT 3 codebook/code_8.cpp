#include <iostream>

using namespace std;

class Base {
public:
  void display() const { cout << "Base display function\n"; }
};

class Derived : public Base {
public:
  void display() const { cout << "Derived display function\n"; }
};

int main() {
  Derived derivedObject;
  Base *basePointer = &derivedObject;

  // Calls Base::display due to static binding
  basePointer->display();

  // Direct call on derived object
  derivedObject.display(); // Calls Derived::display() directly

  return 0;
}