#include <iostream>

using namespace std;

class Counter {
private:
  int value;

public:
  explicit Counter(int initialValue = 0) : value(initialValue) {}

  // Prefix increment (++counter)
  Counter &operator++() {
    ++value;
    return *this;
  }

  // Postfix increment (counter++)
  Counter operator++(int) {
    Counter old = *this;
    ++value;
    return old;
  }

  // Prefix decrement (--counter)
  Counter &operator--() {
    --value;      // Decrease first
    return *this; // Return updated object
  }

  // Postfix decrement (counter--)
  Counter operator--(int) {
    Counter old = *this; // Save old copy
    --value;             // Decrease
    return old;          // Return old copy
  }

  void display() const { cout << value << '\n'; }
};

int main() {
  Counter counter(5);

  // Prefix ++
  cout << "After prefix increment: ";
  ++counter;
  counter.display();

  // Postfix ++
  cout << "Value returned by postfix increment: ";
  Counter oldValue = counter++;
  oldValue.display();

  cout << "Counter after postfix increment: ";
  counter.display();

  // Decrement calls
  cout << "After prefix decrement: ";
  --counter;
  counter.display();

  cout << "Value returned by postfix decrement: ";
  Counter oldDecValue = counter--;
  oldDecValue.display();

  cout << "Counter after postfix decrement: ";
  counter.display();

  return 0;
}