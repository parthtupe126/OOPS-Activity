#include <iostream>
#include <string>

using namespace std;

class Payment {
public:
  virtual void pay(double amount) const = 0;
  virtual ~Payment() = default;
};

class CardPayment : public Payment {
public:
  void pay(double amount) const override {
    cout << "Paid Rs. " << amount << " using card\n";
  }
};

class UpiPayment : public Payment {
public:
  void pay(double amount) const override {
    cout << "Paid Rs. " << amount << " using UPI\n";
  }
};

class NetBankingPayment : public Payment {
public:
  void pay(double amount) const override {
    cout << "Paid Rs. " << amount << " using net banking\n";
  }
};

// WalletPayment derived class
class WalletPayment : public Payment {
public:
  void pay(double amount) const override {
    cout << "Paid Rs. " << amount << " using wallet\n";
  }
};

void processPayment(const Payment &payment, double amount) {
  payment.pay(amount);
}

int main() {
  CardPayment card;
  UpiPayment upi;
  NetBankingPayment netBanking;
  WalletPayment wallet;

  // Standard payment calls
  processPayment(card, 1250.0);
  processPayment(upi, 750.0);
  processPayment(netBanking, 500.0);

  // Wallet payment call
  processPayment(wallet, 350.0);

  return 0;
}