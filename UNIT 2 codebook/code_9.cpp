#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Account {
protected:
  int accountNumber;
  double balance;

public:
  Account(int accNo, double initialBalance)
      : accountNumber(accNo), balance(initialBalance) {}
};

class SavingsAccount : public Account {
private:
  double interestRate;

public:
  SavingsAccount(int accNo, double initialBalance, double rate)
      : Account(accNo, initialBalance), interestRate(rate) {}
  void printDetails() const {
    cout << "Account: " << accountNumber << ", Balance: " << balance
         << ", Rate: " << interestRate << "%\n";
  }
};

int main() {
  SavingsAccount sa(1001, 50000.0, 4.5);
  sa.printDetails();
  return 0;
}