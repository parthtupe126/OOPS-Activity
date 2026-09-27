#include <iostream>

using namespace std;

class Base {
public:
  virtual ~Base() = default;
  void show() const { cout << "Base public function\n"; }
};

class PublicDerived : public Base {};

class PrivateDerived : private Base {
public:
  void callBaseShow() const { show(); }
};

int main() {
  PublicDerived publicObject;
  publicObject.show();

  PrivateDerived privateObject;
  privateObject.callBaseShow();
  return 0;
}