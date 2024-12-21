#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

/*
==========================================================
                    Bank Management System
==========================================================

This program is a simple implementation of a bank account
management system. It allows users to:
- Create new accounts
- Deposit and withdraw funds
- Display account details
- List all accounts
==========================================================
*/

/*
==========================================================
                    INCLUDES AND UTILITIES
==========================================================
The following utility functions are defined:
- clearConsole() to clear the console based on OS
- displayMenu() for user interaction
==========================================================
*/

// Utility function to clear the console
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* 
Class Declaration for Bank Account
----------------------------------
Contains:
- Data Members: Account number, holder's name, balance
- Member Functions:
    - deposit(double)
    - withdraw(double)
    - displayAccountDetails()
*/
class BankAccount {
private:
    int accountNumber;                // Unique account number
    std::string accountHolderName;    // Account holder's name
    double balance;                   // Current balance in the account
    std::string accountType;          // Account type (e.g., Savings, Checking)

public:
    // Constructor
    BankAccount(int accNo, const std::string& name, double initialBalance, const std::string& type)
        : accountNumber(accNo), accountHolderName(name), balance(initialBalance), accountType(type) {}

    /*
    =============================
    Deposit Function
    =============================
    - Adds a specified amount to the account balance
    - Checks for invalid deposits (<= 0)
    */
    void deposit(double amount) {
        if (amount <= 0) {
            std::cerr << "Error: Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        std::cout << "Deposited: " << amount << "\n";
        std::cout << "Updated Balance: " << balance << "\n";
    }

    /*
    =============================
    Withdraw Function
    =============================
    - Deducts a specified amount from the account balance
    - Validates sufficient balance before processing withdrawal
    */
    void withdraw(double amount) {
        if (amount > balance) {
            std::cerr << "Error: Insufficient balance.\n";
            return;
        }
        balance -= amount;
        std::cout << "Withdrew: " << amount << "\n";
        std::cout << "Remaining Balance: " << balance << "\n";
    }

    // Displays account details
    void displayAccountDetails() const {
        std::cout << "\n==============================================\n";
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Account Holder: " << accountHolderName << "\n";
        std::cout << "Account Type: " << accountType << "\n";
        std::cout << "Balance: " << std::fixed << std::setprecision(2) << balance << "\n";
        std::cout << "==============================================\n";
    }

    int getAccountNumber() const { return accountNumber; }
};

// Display the main menu
void displayMenu() {
    /*
    ========================================
    Interactive Menu for User Choices
    ========================================
    Options include:
    1. Create Account
    2. Deposit Money
    3. Withdraw Money
    4. Display Account Details
    5. List All Accounts
    6. Exit
    */
    std::cout << "\n=======================================\n";
    std::cout << "        Bank Management System         \n";
    std::cout << "=======================================\n";
    std::cout << "1. Create New Account\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Display Account Details\n";
    std::cout << "5. List All Accounts\n";
    std::cout << "6. Exit\n";
    std::cout << "=======================================\n";
    std::cout << "Enter your choice: ";
}

BankAccount* findAccount(std::vector<BankAccount>& accounts, int accountNumber) {
    /*
    =========================================
    Search Account Function
    =========================================
    Looks through a vector of BankAccount objects
    to find an account with the given account number.
    =========================================
    */
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

// Function to list all accounts
void listAllAccounts(const std::vector<BankAccount>& accounts) {
    /*
    ====================================================
    Display List of All Accounts
    ====================================================
    Loops through each BankAccount object in the vector
    and prints out its number and holder's name
    ====================================================
    */
    if (accounts.empty()) {
        std::cout << "No accounts available.\n";
        return;
    }
    std::cout << "\nAll Bank Accounts:\n";
    std::cout << "========================================\n";
    for (const auto& account : accounts) {
        std::cout << "Account Number: " << account.getAccountNumber() << "\n";
        std::cout << "Account Holder: " << account.accountHolderName << "\n";
        std::cout << "----------------------------------------\n";
    }
}

int main() {
    /*
    =============================
    Main Function Workflow
    =============================
    - Manages user interactions
    - Loops until user decides to exit
    =============================
    */
    std::vector<BankAccount> accounts;
    int choice, accountNumber;
    double amount;
    std::string name, type;

    do {
        clearConsole();
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
        case 1: // Create a new account
            /*
            ------------------------------------
            Prompt user for new account details:
            - Account Number
            - Holder's Name
            - Initial Balance
            - Account Type
            ------------------------------------
            */
            std::cout << "Enter Account Number: ";
            std::cin >> accountNumber;
            std::cin.ignore();
            std::cout << "Enter Account Holder's Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Account Type (Savings/Checking): ";
            std::getline(std::cin, type);
            std::cout << "Enter Initial Balance: ";
            std::cin >> amount;

            // Add new account to the list
            accounts.emplace_back(accountNumber, name, amount, type);
            std::cout << "Account created successfully!\n";
            break;

        case 2: // Deposit money
            std::cout << "Enter Account Number: ";
            std::cin >> accountNumber;
            {
                BankAccount* account = findAccount(accounts, accountNumber);
                if (account) {
                    std::cout << "Enter Amount to Deposit: ";
                    std::cin >> amount;
                    account->deposit(amount);
                } else {
                    std::cerr << "Error: Account not found.\n";
                }
            }
            break;

        case 3: // Withdraw money
            std::cout << "Enter Account Number: ";
            std::cin >> accountNumber;
            {
                BankAccount* account = findAccount(accounts, accountNumber);
                if (account) {
                    std::cout << "Enter Amount to Withdraw: ";
                    std::cin >> amount;
                    account->withdraw(amount);
                } else {
                    std::cerr << "Error: Account not found.\n";
                }
            }
            break;

        case 4: // Display account details
            std::cout << "Enter Account Number: ";
            std::cin >> accountNumber;
            {
                BankAccount* account = findAccount(accounts, accountNumber);
                if (account) {
                    account->displayAccountDetails();
                } else {
                    std::cerr << "Error: Account not found.\n";
                }
            }
            break;

        case 5: // List all accounts
            listAllAccounts(accounts);
            break;

        case 6: // Exit the program
            std::cout << "Goodbye!\n";
            break;

        default:
            std::cerr << "Invalid option. Try again.\n";
        }
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choice != 6);

    return 0;
}
