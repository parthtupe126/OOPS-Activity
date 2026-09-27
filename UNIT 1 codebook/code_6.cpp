#include <iostream>
using namespace std;

class Demo {
public:
  // Constructor: executes automatically when object is created
  Demo() { cout << "Constructor called"; }

  // Destructor: executes automatically when object goes out of scope
  ~Demo() { cout << "Destructor called"; }
};

int main() {
  // Object created: constructor runs here
  Demo d;

  // Function ends: destructor runs here
  return 0;
}