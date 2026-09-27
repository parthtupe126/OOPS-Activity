#include <iostream>
using namespace std;

// One integer parameter: area of square
int calculateArea(int side) { return side * side; }

// Two integer parameters: area of rectangle
int calculateArea(int length, int width) { return length * width; }

// One double parameter: area of circle
double calculateArea(double radius) { return 3.14 * radius * radius; }

// Two double parameters: area of triangle
double calculateArea(double height, double base) { return 0.5 * height * base; }

int main() {
  // Square calculation
  cout << "Square Area: " << calculateArea(5) << endl;

  // Rectangle calculation
  cout << "Rectangle Area: " << calculateArea(6, 4) << endl;

  // Circle calculation
  cout << "Circle Area: " << calculateArea(2.0) << endl;

  // Triangle calculation
  cout << "Triangle Area: " << calculateArea(5.0, 2.0) << endl;

  return 0; // End program
}