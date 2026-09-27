#include <iostream>
using namespace std;

// Class blueprint definition
class Student {
public:
  string name; // Data member for student name
  int age;     // Data member for student age

  // Member function to display details
  void show() { cout << name << " " << age << endl; }
};

int main() {
  // Object creation
  Student s1;

  // Assign values using dot operator
  s1.name = "Amit";
  s1.age = 20;

  // Call member function
  s1.show();

  return 0;
}