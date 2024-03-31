#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    static int totalTransactions;

public:
    BankAccount(const std::string& accNum, double initBalance) : accountNumber(accNum), balance(initBalance) {}

    // Static method to access total number of transactions
    static int getTotalTransactions() {
        return totalTransactions;
    }

    // Method to perform a transaction (deposit or withdrawal)
    void performTransaction(double amount) {
        balance += amount;
        totalTransactions++;
    }

    // Method to display account information
    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }
};

// Initializing the static variable
int BankAccount::totalTransactions = 0;

int main() {
    std::string accountNumber;
    double initialBalance, transactionAmount;

    std::cout << "Enter account number, initial balance, and transaction amount: ";
    std::cin >> accountNumber >> initialBalance >> transactionAmount;

    BankAccount account(accountNumber, initialBalance);
    account.performTransaction(transactionAmount);

    std::cout << "Account information:" << std::endl;
    account.display();

    std::cout << "Total number of transactions: " << BankAccount::getTotalTransactions() << std::endl;

    return 0;
}
