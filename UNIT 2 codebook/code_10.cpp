#include <iostream>

using namespace std;

class Shape {
public:
  virtual void draw() const { cout << "Drawing generic shape\n"; }
  virtual ~Shape() = default;
};

class Circle : public Shape {
public:
  void draw() const override { cout << "Drawing Circle\n"; }
};

int main() {
  Shape *shapePtr = new Circle();
  shapePtr->draw(); // Calls Circle's draw() due to runtime polymorphism
  delete shapePtr;
  return 0;
}