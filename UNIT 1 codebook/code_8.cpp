#include <iostream>
using namespace std;

class Test {
private:
  int value; // Private variable hidden from outside

public:
  // Parameterized constructor to initialize value
  Test(int v) { value = v; }

  // Inline function for quick execution
  inline int getValue() { return value; }

  // Declare friend function to allow access to private data
  friend void show(Test t);
};

// Friend function definition
void show(Test t) {
  // Accessing private variable 'value' directly
  cout << t.value;
}

int main() {
  // Create object with value 50
  Test obj(50);

  // Call inline getter function
  cout << obj.getValue() << endl;

  // Call friend function
  show(obj);

  return 0;
}