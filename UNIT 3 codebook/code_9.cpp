#include <iostream>

using namespace std;

class Animal {
public:
  virtual void sound() const { cout << "Animal makes a sound\n"; }
  virtual ~Animal() = default;
};

class Dog : public Animal {
public:
  void sound() const override { cout << "Dog barks\n"; }
};

class Cat : public Animal {
public:
  void sound() const override { cout << "Cat meows\n"; }
};

// Cow derived class
class Cow : public Animal {
public:
  void sound() const override { cout << "Cow moos\n"; }
};

int main() {
  Dog dog;
  Cat cat;
  Cow cow;

  Animal *animal = &dog;
  animal->sound();

  animal = &cat;
  animal->sound();

  // Cow sound call
  animal = &cow;
  animal->sound();

  return 0;
}