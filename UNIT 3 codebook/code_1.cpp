#include <iostream>
#include <string>
using namespace std;

// Function to add two integers
int add(int a, int b) { return a + b; }

// Same name, but handles double/decimal numbers
double add(double a, double b) { return a + b; }

// Same name, but takes three integers
int add(int a, int b, int c) { return a + b + c; }

// Same name, but handles string addition
string add(string a, string b) { return a + b; }

int main() {
  // Calls first function (two ints)
  cout << "Sum of two integers: " << add(10, 20) << endl;

  // Calls second function (two doubles)
  cout << "Sum of two doubles: " << add(2.5, 3.7) << endl;

  // Calls third function (three ints)
  cout << "Sum of three integers: " << add(10, 20, 30) << endl;

  // Calls fourth function (two strings)
  cout << "Addition/Concatenation of two strings: " << add("Hello", "World")
       << endl;
  return 0; // End program
}