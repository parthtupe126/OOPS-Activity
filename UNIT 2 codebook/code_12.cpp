#include <iostream>

using namespace std;

class Device {
public:
  int power = 100;
};

class Computer : virtual public Device {};
class Phone : virtual public Device {};

class SmartWatch : public Computer, public Phone {
public:
  void showPower() const { cout << "Power: " << power << '\n'; }
};

int main() {
  SmartWatch watch;
  watch.showPower(); // No ambiguity because Device is inherited virtually
  return 0;
}