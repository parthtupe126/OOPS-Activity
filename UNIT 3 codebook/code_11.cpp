#include <iostream>

using namespace std;

class Shape {
public:
  virtual double area() const = 0; // Pure virtual function
  virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
  double length;
  double width;

public:
  Rectangle(double givenLength, double givenWidth)
      : length(givenLength), width(givenWidth) {}

  double area() const override { return length * width; }
};

// Triangle class with formula 0.5 * base * height
class Triangle : public Shape {
private:
  double base;
  double height;

public:
  Triangle(double givenBase, double givenHeight)
      : base(givenBase), height(givenHeight) {}

  double area() const override {
    return 0.5 * base * height; // 0.5 * base * height
  }
};

int main() {
  Rectangle rectangle(8.0, 4.0);
  cout << "Rectangle Area: " << rectangle.area() << '\n';

  // Triangle call
  Triangle triangle(6.0, 4.0);
  cout << "Triangle Area: " << triangle.area() << '\n';

  return 0;
}