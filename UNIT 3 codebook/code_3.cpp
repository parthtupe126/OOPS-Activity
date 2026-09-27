#include <iostream>

using namespace std;

// Number class
class Number {
private:
  int value;

public:
  explicit Number(int givenValue) : value(givenValue) {}

  // Overloads unary '-'
  Number operator-() const { return Number(-value); }

  void display() const { cout << value << '\n'; }
};

// Balance class with unary minus
class Balance {
private:
  double value; // Stores the balance amount

public:
  explicit Balance(double givenValue) : value(givenValue) {}

  // Overloads unary '-' for Balance
  Balance operator-() const { return Balance(-value); }

  void display() const { cout << value << '\n'; }
};

int main() {
  // Number execution
  Number first(25);
  Number second = -first;

  cout << "Original value: ";
  first.display();

  cout << "Negated value: ";
  second.display();

  // Balance execution
  Balance originalBalance(1500.50);
  Balance negativeBalance = -originalBalance;

  cout << "Original balance: ";
  originalBalance.display();

  cout << "Negated balance: ";
  negativeBalance.display();

  return 0;
}