#include <iostream>

using namespace std;

class Appliance {
public:
  virtual void turnOn() = 0; // Pure virtual function
  virtual ~Appliance() = default;
};

class Fan : public Appliance {
public:
  void turnOn() override { cout << "Fan is spinning\n"; }
};

int main() {
  // Appliance a; // Error: Cannot create an object of an abstract class
  Fan f;
  f.turnOn();
  return 0;
}