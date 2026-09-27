#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Vehicle {
protected:
  string model;
  double dailyRate;

public:
  Vehicle(string m, double rate) : model(move(m)), dailyRate(rate) {}
  virtual double calculateCost(int days) const { return dailyRate * days; }
  virtual void displayInfo() const {
    cout << "Model: " << model << ", Daily Rate: $" << dailyRate << '\n';
  }
  virtual ~Vehicle() = default;
};

class LuxuryCar : public Vehicle {
private:
  double luxuryTax;

public:
  LuxuryCar(string m, double rate, double tax)
      : Vehicle(move(m), rate), luxuryTax(tax) {}
  double calculateCost(int days) const override {
    return (dailyRate + luxuryTax) * days;
  }
};

int main() {
  Vehicle *rental = new LuxuryCar("Mercedes S-Class", 150.0, 50.0);
  rental->displayInfo();
  cout << "Total Cost for 3 Days: $" << rental->calculateCost(3) << '\n';
  delete rental;
  return 0;
}