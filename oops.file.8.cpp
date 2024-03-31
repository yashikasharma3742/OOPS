#include <iostream>

class BankAccount {
private:
    static int totalTransactions;
    int accountNumber;
    double balance;

public:
    
    BankAccount(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

    
    static int getTotalTransactions() {
        return totalTransactions;
    }

    
    void deposit(double amount) {
        balance += amount;
        totalTransactions++;
    }


    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            totalTransactions++;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    
    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};


int BankAccount::totalTransactions = 0;

int main() {
    
    BankAccount acc1(1516, 5000);
    BankAccount acc2(1035, 8000);

    
    acc1.deposit(2000);
    acc2.withdraw(3000);

    
    acc1.display();
    acc2.display();
    
    std::cout << "Total Transactions: " << BankAccount::getTotalTransactions() << std::endl;

    return 0;
}
