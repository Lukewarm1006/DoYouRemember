#include <iostream>
#include <string>

class BankAccount {
 protected:
  std::string owner;
  double balance;

 public:
  BankAccount(std::string name, double initialBalance)
      : owner(name), balance(initialBalance) {}

  void deposit(double amount) { balance += amount; };

  virtual void withdraw(double amount) {
    if (amount > balance) {
      std::cout << "Insufficient Funds" << std::endl;
      return;
    }
    balance -= amount;
  }

  void printBalance() { std::cout << owner << ": " << balance << std::endl; }

  virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
 private:
  double interestRate;

 public:
  SavingsAccount(std::string name, double initialBalance, double rate)
      : BankAccount(name, initialBalance), interestRate(rate) {}

  void applyInterest() { balance = balance * (1 + interestRate); }
};

class CurrentAccount : public BankAccount {
 private:
  double overdraftLimit;

 public:
  CurrentAccount(std::string name, double initialBalance, double limit)
      : BankAccount(name, initialBalance), overdraftLimit(limit) {}

      void withdraw(double amount) {
    if (amount > balance + overdraftLimit) {
      std::cout << "Insufficient Funds" << std::endl;
      return;
    }
    balance -= amount;
  }
};

int main() {
  BankAccount* accounts[2];

  accounts[0] = new SavingsAccount("Luke", 1000, 0.05);
  accounts[1] = new CurrentAccount("Bob", 500, 200);

  for (int i = 0; i < 2; i++) {
    accounts[i]->withdraw(600);
    accounts[i]->printBalance();
  }

  delete accounts[0];
    delete accounts[1];
}