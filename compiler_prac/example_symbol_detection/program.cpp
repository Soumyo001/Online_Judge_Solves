#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <map>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct Account {
    int accountNumber;
    string holderName;
    double balance;
};

// Function prototypes
void displayMenu();
void createAccount(vector<Account>& accounts);
void deposit(vector<Account>& accounts);
void withdraw(vector<Account>& accounts);
void checkBalance(const vector<Account>& accounts);
void deleteAccount(vector<Account>& accounts);
void displayAllAccounts(const vector<Account>& accounts);
bool validateAccountNumber(int accountNumber);

// Function to display the menu
void displayMenu() {
    cout << "\n======== Bank Management System ========\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Delete Account\n";
    cout << "6. Display All Accounts\n";
    cout << "7. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

// Function to create a new account
void createAccount(vector<Account>& accounts) {
    Account acc;
    cout << "\nEnter Account Number: ";
    cin >> acc.accountNumber;

    // Check for duplicate account number
    for (const auto& account : accounts) {
        if (account.accountNumber == acc.accountNumber) {
            cout << "\nAccount number already exists. Try again.\n";
            return;
        }
    }

    cin.ignore(); // To clear newline from buffer
    cout << "Enter Account Holder's Name: ";
    getline(cin, acc.holderName);
    cout << "Enter Initial Deposit: ";
    cin >> acc.balance;

    accounts.push_back(acc);
    cout << "\nAccount created successfully!\n";
}

// Function to deposit money
void deposit(vector<Account>& accounts) {
    int accountNumber;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            if (amount <= 0) {
                cout << "\nInvalid amount. Deposit failed.\n";
                return;
            }
            account.balance += amount;
            cout << "\nDeposit successful! New Balance: " << account.balance << '\n';
            return;
        }
    }

    cout << "\nAccount not found.\n";
}

// Function to withdraw money
void withdraw(vector<Account>& accounts) {
    int accountNumber;
    double amount;

    /*  this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
        this is a multiline comment.
    */  

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            if (amount > account.balance || amount <= 0) {
                cout << "\nInvalid amount. Withdrawal failed.\n";
                return;
            }
            account.balance -= amount;
            cout << "\nWithdrawal successful! New Balance: " << account.balance << '\n';
            return;
        }
    }

    cout << "\nAccount not found.\n";
}

// Function to check account balance
void checkBalance(const vector<Account>& accounts) {
    int accountNumber;
    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    for (const auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            cout << "\nAccount Holder: " << account.holderName
                 << "\nBalance: " << account.balance << '\n';
            return;
        }
    }

    cout << "\nAccount not found.\n";
}

// Function to delete an account
void deleteAccount(vector<Account>& accounts) {
    int accountNumber;
    cout << "\nEnter Account Number to Delete: ";
    cin >> accountNumber;

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->accountNumber == accountNumber) {
            accounts.erase(it);
            cout << "\nAccount deleted successfully!\n";
            return;
        }
    }

    cout << "\nAccount not found.\n";
}

// Function to display all accounts
void displayAllAccounts(const vector<Account>& accounts) {
    if (accounts.empty()) {
        cout << "\nNo accounts found.\n";
        return;
    }

    cout << "\n=== List of All Accounts ===\n";
    cout << left << setw(15) << "Account No." << setw(20) << "Holder Name" << setw(10) << "Balance\n";
    cout << "------------------------------------------\n";

    for (const auto& account : accounts) {
        cout << left << setw(15) << account.accountNumber
             << setw(20) << account.holderName
             << setw(10) << account.balance << '\n';
    }
}

// Main program
int main() {
    vector<Account> accounts;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            createAccount(accounts);
            break;
        case 2:
            deposit(accounts);
            break;
        case 3:
            withdraw(accounts);
            break;
        case 4:
            checkBalance(accounts);
            break;
        case 5:
            deleteAccount(accounts);
            break;
        case 6:
            displayAllAccounts(accounts);
            break;
        case 7:
            cout << "\nThank you for using the Bank Management System. Goodbye!\n";
            return 0;
        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}