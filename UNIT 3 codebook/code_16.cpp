#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Employee {
protected:
  int employeeId;
  string name;

public:
  Employee(int id, string employeeName)
      : employeeId(id), name(move(employeeName)) {}

  virtual double calculateSalary() const = 0;

  void displayBasicDetails() const {
    cout << "Employee ID: " << employeeId << '\n';
    cout << "Name: " << name << '\n';
  }

  virtual ~Employee() = default;
};

class PermanentEmployee : public Employee {
private:
  double basicSalary;
  double allowance;
  double taxRate; // Tax rate for permanent employees

public:
  PermanentEmployee(int id, string employeeName, double basic, double extra,
                    double tax = 0.10)
      : Employee(id, move(employeeName)), basicSalary(basic), allowance(extra),
        taxRate(tax) {}

  // Calculate salary with tax deduction
  double calculateSalary() const override {
    double gross = basicSalary + allowance;
    return gross - (gross * taxRate); // Deduct tax
  }
};

class ContractEmployee : public Employee {
private:
  double hourlyRate;
  int hoursWorked;

public:
  ContractEmployee(int id, string employeeName, double rate, int hours)
      : Employee(id, move(employeeName)), hourlyRate(rate), hoursWorked(hours) {
  }

  double calculateSalary() const override { return hourlyRate * hoursWorked; }
};

// FreelanceEmployee class
class FreelanceEmployee : public Employee {
private:
  int projectsCompleted;
  double ratePerProject;

public:
  FreelanceEmployee(int id, string employeeName, int projects,
                    double projectRate)
      : Employee(id, move(employeeName)), projectsCompleted(projects),
        ratePerProject(projectRate) {}

  double calculateSalary() const override {
    return projectsCompleted * ratePerProject;
  }
};

// Print pay slip function
void printPaySlip(const Employee &employee) {
  employee.displayBasicDetails();
  cout << "Salary: Rs. " << employee.calculateSalary() << "\n\n";
}

int main() {
  // Basic objects
  PermanentEmployee permanentEmployee(101, "Asha", 40000.0, 8000.0);
  ContractEmployee contractEmployee(102, "Vikas", 500.0, 80);

  // Pay slip calls
  printPaySlip(permanentEmployee);
  printPaySlip(contractEmployee);

  // Store employees using vector<unique_ptr<Employee>>
  vector<unique_ptr<Employee>> staff;
  staff.push_back(make_unique<PermanentEmployee>(101, "Asha", 40000.0, 8000.0));
  staff.push_back(make_unique<ContractEmployee>(102, "Vikas", 500.0, 80));
  staff.push_back(
      make_unique<FreelanceEmployee>(103, "Rohan", 4, 15000.0)); // Freelancer

  // Display total payroll amount
  double totalPayroll = 0.0;
  cout << "--- Polymorphic Vector Payroll List ---\n";
  for (const auto &emp : staff) {
    emp->displayBasicDetails();
    double sal = emp->calculateSalary();
    cout << "Salary: Rs. " << sal << "\n\n";
    totalPayroll += sal;
  }
  cout << "Total Payroll Amount: Rs. " << totalPayroll << '\n';

  return 0;
}