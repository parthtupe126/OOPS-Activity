#include <iostream>

using namespace std;

class Distance {
private:
  int meters;

public:
  explicit Distance(int value) : meters(value) {}

  // Overloads '>'
  bool operator>(const Distance &other) const { return meters > other.meters; }

  // Overload '==' to test equality
  bool operator==(const Distance &other) const {
    return meters == other.meters;
  }

  void display() const { cout << meters << " meters\n"; }
};

int main() {
  Distance first(120);
  Distance second(90);

  cout << "First distance: ";
  first.display();

  cout << "Second distance: ";
  second.display();

  // '>' check
  if (first > second) {
    cout << "First distance is greater\n";
  } else {
    cout << "Second distance is greater or equal\n";
  }

  // '==' check
  Distance third(120);
  if (first == third) {
    cout << "First distance and third distance are equal\n";
  } else {
    cout << "First distance and third distance are not equal\n";
  }

  return 0;
}