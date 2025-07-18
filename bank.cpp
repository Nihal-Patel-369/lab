#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;
    string password;

public:
    Account(int accNum, string accHolder, double bal, string pass)
    {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = bal;
        password = pass;
    }

    int getaccountNumber()
    {
        return accountNumber;
    }

    bool verifyPassword(string pass)
    {
        return password == pass;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber
             << ", Account Holder: " << accountHolderName
             << ", Balance: $" << balance << endl;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Deposit amount must be positive.\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds or invalid amount.\n";
        }
    }

    bool matchesAccount(int accNum)
    {
        return accountNumber == accNum;
    }
};

vector<Account> accounts;

void addAccount()
{
    int accNumber;
    string name, password;
    double initialBalance;
    cout << "Enter Account Number: ";
    cin >> accNumber;
    cin.ignore();
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;
    cin.ignore();
    cout << "Enter Password: ";
    getline(cin, password);
    Account newAccount(accNumber, name, initialBalance, password);
    accounts.push_back(newAccount);
    cout << "================================================================================\n";
    cout << "Account added successfully!\n";
    cout << "================================================================================\n";
}
void displayMenue()
{
    cout << "\n=========  BANKING SYSTEM MENU =========\n";
    cout << "1. Create Account\n";
    cout << "2. Access Account (Login)\n";
    cout << "3. Exit\n";
    cout << "==========================================\n";
}
void accessAccount()
{
    int accNumber;
    string password;
    bool found = false;

    cout << "\n🔐 Enter Account Number: ";
    cin >> accNumber;

    cout << "🔑 Enter Password: ";
    cin >> password;

    for (auto &acc : accounts)
    {
        if (acc.matchesAccount(accNumber))
        {
            found = true;
            if (acc.verifyPassword(password))
            {
                cout << "\n Login successful!\n";

                int choice;
                double amount;

                do
                {
                    cout << "\n---- Account Menu ----\n";
                    cout << "1. Deposit\n";
                    cout << "2. Withdraw\n";
                    cout << "3. Show Account Details\n";
                    cout << "4. Exit\n";
                    cout << "Choose an option: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        cout << "Enter amount to deposit: ₹";
                        cin >> amount;
                        acc.deposit(amount);
                        break;
                    case 2:
                        cout << "Enter amount to withdraw: ₹";
                        cin >> amount;
                        acc.withdraw(amount);
                        break;
                    case 3:
                        acc.display();
                        break;
                    case 4:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid option.\n";
                    }
                } while (choice != 4);
            }
            else
            {
                cout << "Incorrect password!\n";
            }
            break;
        }
    }

    if (!found)
    {
        cout << " Account not found.\n";
    }
}

int main()
{

    int choice;

    cout << "=====================================\n";
    cout << "     WELCOME TO SIMPLE BANK SYSTEM   \n";
    cout << "=====================================\n";

    do
    {
        displayMenue();
        cout << "Please select an option from the menu above:\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            accessAccount();
            break;
        case 3:
            cout << " Exiting... Thank you for using the Bank System!\n";
            break;
        default:
            cout << " Invalid option. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
