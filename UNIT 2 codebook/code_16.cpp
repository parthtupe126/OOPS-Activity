#include <iostream>
#include <string>
#include <utility>
#include <vector>


using namespace std;

class Employee {
protected:
  string name;
  int id;

public:
  Employee(string empName, int empId) : name(move(empName)), id(empId) {}
  virtual double calculateSalary() const = 0; // Pure virtual
  virtual void printDetails() const {
    cout << "ID: " << id << ", Name: " << name;
  }
  virtual ~Employee() = default;
};

class SalariedEmployee : public Employee {
private:
  double monthlySalary;

public:
  SalariedEmployee(string empName, int empId, double salary)
      : Employee(move(empName), empId), monthlySalary(salary) {}
  double calculateSalary() const override { return monthlySalary; }
  void printDetails() const override {
    Employee::printDetails();
    cout << ", Monthly Pay: $" << calculateSalary() << '\n';
  }
};

int main() {
  SalariedEmployee emp("Kavita", 301, 75000.0);
  emp.printDetails();
  return 0;
}