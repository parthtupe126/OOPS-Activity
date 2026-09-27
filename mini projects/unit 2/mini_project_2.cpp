#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Account {
protected:
  int accountNumber;
  string holderName;
  double balance;

public:
  Account(int accNo, string name, double initialBalance)
      : accountNumber(accNo), holderName(name), balance(initialBalance) {}

  virtual void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      cout << "Deposited Rs. " << amount << " into Account " << accountNumber
           << endl;
    }
  }

  virtual void withdraw(double amount) {
    if (amount <= balance) {
      balance -= amount;
      cout << "Withdrew Rs. " << amount << " from Account " << accountNumber
           << endl;
    } else {
      cout << "Insufficient funds in Account " << accountNumber << endl;
    }
  }

  virtual void calculateInterest() = 0; // Pure virtual function

  virtual void displayDetails() const {
    cout << "Account No: " << accountNumber << " | Holder: " << holderName
         << " | Balance: Rs. " << balance;
  }

  virtual ~Account() = default;
};

class SavingsAccount : public Account {
private:
  double interestRate; // e.g., 4.0%

public:
  SavingsAccount(int accNo, string name, double balance, double rate)
      : Account(accNo, name, balance), interestRate(rate) {}

  void calculateInterest() override {
    double interest = balance * (interestRate / 100.0);
    balance += interest;
    cout << "Savings Interest Added: Rs. " << interest << endl;
  }

  void displayDetails() const override {
    cout << "Savings Account | ";
    Account::displayDetails();
    cout << " | Rate: " << interestRate << "%" << endl;
  }
};

class CurrentAccount : public Account {
private:
  double overdraftLimit;

public:
  CurrentAccount(int accNo, string name, double balance, double limit)
      : Account(accNo, name, balance), overdraftLimit(limit) {}

  void withdraw(double amount) override {
    if (amount <= balance + overdraftLimit) {
      balance -= amount;
      cout << "Withdrew Rs. " << amount << " (Current Account)" << endl;
    } else {
      cout << "Overdraft limit exceeded for Account " << accountNumber << endl;
    }
  }

  void calculateInterest() override {
    cout << "Current Accounts do not earn interest." << endl;
  }

  void displayDetails() const override {
    cout << "Current Account | ";
    Account::displayDetails();
    cout << " | Overdraft Limit: Rs. " << overdraftLimit << endl;
  }
};

class FixedDepositAccount : public Account {
private:
  int tenureMonths;
  double interestRate;

public:
  FixedDepositAccount(int accNo, string name, double balance, int tenure,
                      double rate)
      : Account(accNo, name, balance), tenureMonths(tenure),
        interestRate(rate) {}

  void withdraw(double amount) override {
    cout << "Withdrawal blocked: Fixed Deposit locked for " << tenureMonths
         << " months." << endl;
  }

  void calculateInterest() override {
    double interest = balance * (interestRate / 100.0) * (tenureMonths / 12.0);
    balance += interest;
    cout << "Fixed Deposit Interest Added: Rs. " << interest << endl;
  }

  void displayDetails() const override {
    cout << "Fixed Deposit   | ";
    Account::displayDetails();
    cout << " | Tenure: " << tenureMonths << " months | Rate: " << interestRate
         << "%" << endl;
  }
};

int main() {
  vector<unique_ptr<Account>> bank;

  bank.push_back(make_unique<SavingsAccount>(1001, "Amit Kumar", 50000.0, 4.0));
  bank.push_back(
      make_unique<CurrentAccount>(1002, "Tech Corp", 100000.0, 25000.0));
  bank.push_back(
      make_unique<FixedDepositAccount>(1003, "Sneha Patel", 200000.0, 12, 7.0));

  cout << "================ BANK ACCOUNT SYSTEM ================" << endl;
  for (const auto &acc : bank) {
    acc->displayDetails();
  }

  cout << "\n--- Processing Transactions ---" << endl;
  bank[0]->deposit(10000);
  bank[0]->calculateInterest();

  bank[1]->withdraw(115000); // Uses overdraft

  bank[2]->withdraw(5000); // Should fail due to lock
  bank[2]->calculateInterest();

  cout << "\n================ UPDATED STATUS ================" << endl;
  for (const auto &acc : bank) {
    acc->displayDetails();
  }

  return 0;
}