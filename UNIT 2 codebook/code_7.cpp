#include <iostream>

using namespace std;

class Printer {
public:
  virtual ~Printer() = default;
  void print() const { cout << "Printing document...\n"; }
};

class Scanner {
public:
  virtual ~Scanner() = default;
  void print() const { cout << "Printing scan preview...\n"; }
};

class AllInOne : public Printer, public Scanner {
public:
  void printFromBoth() const {
    Printer::print();
    Scanner::print();
  }
};

int main() {
  AllInOne machine;
  // machine.print(); // Ambiguous: compiler doesn't know which print() to call
  machine.Printer::print();
  machine.Scanner::print();
  return 0;
}