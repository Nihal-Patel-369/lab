#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, accountHolderName);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        cout << "\n----------------------------------------------------------------\n";
        cout << " Account created successfully!\n";
        cout << "----------------------------------------------------------------\n";
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "\n----------------------------------------------------------------\n";
            cout << "Deposited successfully. New Balance: " << balance << endl;
            cout << "----------------------------------------------------------------\n";
        } else {
            cout << "----------------------------------------------------------------\n";

            cout << " Invalid amount!\n";
            cout << "----------------------------------------------------------------\n";
        }
    }
    
    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "----------------------------------------------------------------\n";
            cout << "Withdrawal successful. New Balance: " << balance << endl;
            cout << "----------------------------------------------------------------\n";
        } else {
            cout << "----------------------------------------------------------------\n";
            cout << "Insufficient balance or invalid amount.\n";
            cout << "----------------------------------------------------------------\n";
        }
    }

    void checkBalance() {
        cout << "\n=============================================================\n";
        cout << " Current Balance: " << balance << endl;
        cout << "\n=============================================================\n";
    }

    void displayAccountDetails() {
        cout << "==========================================================================\n";
        cout << "| Account Number: " << accountNumber<< "      |" << endl;
        cout << "---------------------------------------------------------------------------\n";
        cout << "| Account Holder: " << accountHolderName<< "    |" << endl;
        cout << "---------------------------------------------------------------------------\n";
        cout << "| Balance: " << balance<< "   |" << endl;
        cout << "---------------------------------------------------------------------------\n";
    }

    int getAccountNumber() {
        return accountNumber;
    }
};

int main() {
    const int MAX_ACCOUNTS = 100;
    BankAccount accounts[MAX_ACCOUNTS];
    int totalAccounts = 0;

    int choice;
    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit to Account\n";
        cout << "3. Withdraw from Account\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int accNum, foundIndex;

        switch (choice) {
        case 1:
            if (totalAccounts < MAX_ACCOUNTS) {
                accounts[totalAccounts].createAccount();
                totalAccounts++;
            } else {
                cout << "❌ Cannot create more accounts.\n";
            }
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNum;
            foundIndex = -1;
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    foundIndex = i;
                    break;
                }
            }
            if (foundIndex != -1) {
                accounts[foundIndex].deposit();
            } else {
                cout << "❌ Account not found!\n";
            }
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNum;
            foundIndex = -1;
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    foundIndex = i;
                    break;
                }
            }
            if (foundIndex != -1) {
                accounts[foundIndex].withdraw();
            } else {
                cout << "❌ Account not found!\n";
            }
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNum;
            foundIndex = -1;
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    foundIndex = i;
                    break;
                }
            }
            if (foundIndex != -1) {
                accounts[foundIndex].checkBalance();
            } else {
                cout << "Account not found!\n";
            }
            break;

        case 5:
            cout << "Enter Account Number: ";
            cin >> accNum;
            foundIndex = -1;
            for (int i = 0; i < totalAccounts; i++) {
                if (accounts[i].getAccountNumber() == accNum) {
                    foundIndex = i;
                    break;
                }
            }
            if (foundIndex != -1) {
                accounts[foundIndex].displayAccountDetails();
            } else {
                cout << " Account not found!\n";
            }
            break;

        case 6:
            cout << "Thank you for using the banking system!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }

    } while (choice != 6);

    return 0;
}
