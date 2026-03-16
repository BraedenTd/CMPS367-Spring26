// Homework Development.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

class BankAccount
{
    private:
        string accountHolderName;
        int accountNumber;
        double balance;

    public:
        // Constructor to initialize the account details
        BankAccount()
        {
            accountHolderName = "";
            accountNumber = 0;
            balance = 0.0;
        }

        BankAccount(string name, int number, double initialBalance)
        {
            accountHolderName = name;
            accountNumber = number;
            balance = initialBalance;
        }

        // Function to deposit money
        void deposit(double amount)
        {
            balance += amount;
        }

        // Function to withdraw money
        bool withdraw(double amount)
        {
            if (amount <= balance)
            {
                balance -= amount;
                return true;
            }
            return false;
        }

        // Function to display the account balance
        void displayBalance()
        {
            cout << "Account Holder : " << accountHolderName << endl;
            cout << "Account Number : " << accountNumber << endl;
            cout << "Current Balance: $" << balance << endl;
        }

        // Getters
        int getAccountNumber()   { return accountNumber; }
        double getBalance()      { return balance; }
        string getName()         { return accountHolderName; }
};

// -------------------------------------------------------
// Global account storage and counter
// -------------------------------------------------------
BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;
int nextAccountNumber = 1001;

// -------------------------------------------------------
// Helper: find an account index by account number
// Returns -1 if not found
// -------------------------------------------------------
int findAccount(int accNum)
{
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i].getAccountNumber() == accNum)
            return i;
    }
    return -1;
}

// -------------------------------------------------------
// Helper: pause and return to menu
// -------------------------------------------------------
void returnToMenu()
{
    cout << "\nPress any key to return to the Main Menu...";
    cin.ignore();
    cin.get();
}

// -------------------------------------------------------
// Option 1: Create a new account
// -------------------------------------------------------
void createAccount()
{
    string name;
    double initialBalance;

    cout << "\n--- Create a New Bank Account ---" << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    int newAccNum = nextAccountNumber++;
    accounts[accountCount] = BankAccount(name, newAccNum, initialBalance);
    accountCount++;

    cout << "\nAccount created successfully!" << endl;
    cout << "Account Holder : " << name << endl;
    cout << "Account Number : " << newAccNum << endl;
    cout << "Current Balance: $" << initialBalance << endl;

    returnToMenu();
}

// -------------------------------------------------------
// Option 2: Deposit money
// -------------------------------------------------------
void depositMoney()
{
    int accNum;
    double amount;

    cout << "\n--- Deposit Money to an Account ---" << endl;
    cout << "Enter your account number: ";
    cin >> accNum;

    int index = findAccount(accNum);

    if (index == -1)
    {
        cout << "Account number " << accNum << " does not exist." << endl;
    }
    else
    {
        cout << "Enter the amount to deposit: $";
        cin >> amount;

        accounts[index].deposit(amount);

        cout << "\nSuccessfully deposited $" << amount << "." << endl;
        cout << "Current Balance: $" << accounts[index].getBalance() << endl;
    }

    returnToMenu();
}

// -------------------------------------------------------
// Option 3: Withdraw money
// -------------------------------------------------------
void withdrawMoney()
{
    int accNum;
    double amount;

    cout << "\n--- Withdraw Money from an Account ---" << endl;
    cout << "Enter your account number: ";
    cin >> accNum;

    int index = findAccount(accNum);

    if (index == -1)
    {
        cout << "Account number " << accNum << " does not exist." << endl;
    }
    else
    {
        cout << "Enter the amount to withdraw: $";
        cin >> amount;

        if (!accounts[index].withdraw(amount))
        {
            cout << "Insufficient funds. Your current balance is $"
                 << accounts[index].getBalance() << "." << endl;
        }
        else
        {
            cout << "\nSuccessfully withdrew $" << amount << "." << endl;
            cout << "Current Balance: $" << accounts[index].getBalance() << endl;
        }
    }

    returnToMenu();
}

// -------------------------------------------------------
// Option 4: Display balance
// -------------------------------------------------------
void displayBalance()
{
    int accNum;

    cout << "\n--- Display Current Balance ---" << endl;
    cout << "Enter your account number: ";
    cin >> accNum;

    int index = findAccount(accNum);

    if (index == -1)
    {
        cout << "Account number " << accNum << " does not exist." << endl;
    }
    else
    {
        cout << endl;
        accounts[index].displayBalance();
    }

    returnToMenu();
}

// -------------------------------------------------------
// Main Menu
// -------------------------------------------------------
void displayMenu()
{
    cout << "\n***************Welcome to the Bank***************" << endl;
    cout << "Type a number that you would like to perform" << endl;
    cout << "1 - Create a new bank account with an initial balance" << endl;
    cout << "2 - Deposit Money to an Account" << endl;
    cout << "3 - Withdraw Money from an Account" << endl;
    cout << "4 - Display Current Balance of an Account" << endl;
    cout << "5 - Exit" << endl;
    cout << "--> ";
}

int main()
{
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1: createAccount();   break;
            case 2: depositMoney();    break;
            case 3: withdrawMoney();   break;
            case 4: displayBalance();  break;
            case 5: cout << "Thank you for banking with us. Goodbye!" << endl; break;
            default: cout << "Invalid option. Please enter a number from 1 to 5." << endl;
        }

    } while (choice != 5);

    return 0;
}