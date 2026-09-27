#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Shape {
public:
  virtual double area() const = 0;
  virtual void displayName() const = 0;
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

  void displayName() const override { cout << "Rectangle"; }
};

class Circle : public Shape {
private:
  double radius;

public:
  explicit Circle(double givenRadius) : radius(givenRadius) {}

  double area() const override {
    constexpr double PI = 3.141592653589793;
    return PI * radius * radius;
  }

  void displayName() const override { cout << "Circle"; }
};

// Triangle derived class
class Triangle : public Shape {
private:
  double base;
  double height;

public:
  Triangle(double givenBase, double givenHeight)
      : base(givenBase), height(givenHeight) {}

  double area() const override { return 0.5 * base * height; }

  void displayName() const override { cout << "Triangle"; }
};

int main() {
  vector<unique_ptr<Shape>> shapes;
  shapes.push_back(make_unique<Rectangle>(5.0, 3.0));
  shapes.push_back(make_unique<Circle>(2.0));

  // Triangle added to vector
  shapes.push_back(make_unique<Triangle>(4.0, 5.0));

  for (const auto &shape : shapes) {
    shape->displayName();
    cout << " Area: " << shape->area() << '\n';
  }

  return 0;
}