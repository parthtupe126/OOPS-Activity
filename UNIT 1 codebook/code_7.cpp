#include <iostream>
using namespace std;

class Student {
public:
  // Shared static count variable across all objects
  static int count;

  // Constructor runs whenever a new object is created
  Student() {
    count++; // Increase shared count
  }
};

// Define and initialize static variable outside class
int Student::count = 0;

int main() {
  // Creating three objects
  Student s1, s2, s3;

  // Access static variable using class name
  cout << Student::count;

  return 0;
}