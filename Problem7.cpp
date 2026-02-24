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

  void withdraw(double amount) {
    if (amount > balance) {
      std::cout << "Insufficient Funds" << std::endl;
      return;
    }
    balance -= amount;
  }

  void printBalance() { std::cout << owner << ": " << balance << std::endl; }
};

class SavingsAccount : public BankAccount {
 private:
  double interestRate;

 public:
  SavingsAccount(std::string name, double initialBalance, double rate)
      : BankAccount(name, initialBalance), interestRate(rate) {}

  void applyInterest() {
    balance = balance * (1 + interestRate);
  }
};

int main() {
    SavingsAccount incentiveSaver("Luke", 1000, 0.05);

    incentiveSaver.printBalance();
    incentiveSaver.applyInterest();
    incentiveSaver.printBalance();
    incentiveSaver.deposit(500);
    incentiveSaver.printBalance();
    incentiveSaver.applyInterest();
    incentiveSaver.printBalance();
}