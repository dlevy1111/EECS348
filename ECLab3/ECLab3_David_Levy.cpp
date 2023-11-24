#include <iostream>
#include <string>
using namespace std;

// Account (parent) class
class Account
{

    // Public items, like name, balance, etc.
    // Need to be accessed by children classes.
public:
    string accountNumber;
    string accountHolder;
    float balance;

    void displayDetails() {} // Defined here but actually described later.

    void withdraw(float amount) // to ber overwritten
    {
        if (balance >= amount)
        {
            balance = balance - amount;
        }
        else
            cout << "The balance wasn't high enough to take that amount out!" << endl;
    }

    void deposit(float amount)
    {
        balance = balance + amount;
    }
};

// Savings (derived) class
class SavingsAccount : public Account
{

public:
    // personal variables to be defined later
    float interestRate;
    float minimumBalance; // undefined in the problem.

    SavingsAccount(string id, string name, float bal, float intRate)
    {
        accountNumber = id;
        accountHolder = name;
        balance = bal;
        interestRate = intRate;
        minimumBalance = 1000; // a value I chose.
    }

    // overwritten display function
    void displayDetails()
    {
        cout << "Account Details for Savings Account (ID: " << accountNumber << "):" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
    }

    // overwritten withdrawl function
    float withdraw(float amount)
    {
        if (balance - amount > minimumBalance)
        {
            balance = balance - amount;
            return amount;
        }
        else
        {
            balance = 0;
            return minimumBalance;
        }
    }

    // overloading "+" operator
    SavingsAccount operator+(SavingsAccount &other)
    {
        SavingsAccount result = SavingsAccount(accountNumber, accountHolder, balance, interestRate); // copy this account

        float depositAmount = other.withdraw(9999999999);

        result.deposit(depositAmount);
        return result;
    }
};

// Checking (derived) class
class CurrentAccount : public Account
{

public:
    // personal variable to be defined later
    float overdraftLimit;

    CurrentAccount(string id, string name, float bal, float limit)
    {
        accountNumber = id;
        accountHolder = name;
        balance = bal;
        overdraftLimit = -limit;
    }

    // overwritten display function
    void displayDetails()
    {
        cout << "Account Details for Current Account (ID: " << accountNumber << "):" << endl;
        cout << "Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }

    // overwritten withdrawl function
    float withdraw(float amount)
    {
        if (overdraftLimit < balance - amount)
        {
            balance = balance - amount;
            return amount;
        }
        else
        {
            balance = balance - overdraftLimit;
            return overdraftLimit;
        }
    }

    // overloading "+" operator
    CurrentAccount operator+(CurrentAccount &other)
    {
        CurrentAccount result = CurrentAccount(accountNumber, accountHolder, balance, overdraftLimit); // make a copy of this account

        float depositAmount = other.withdraw(9999999999);

        result.deposit(depositAmount);
        return result;
    }

    CurrentAccount operator+(SavingsAccount &other)
    {
        CurrentAccount result = CurrentAccount(accountNumber, accountHolder, balance, overdraftLimit); // make a copy of this account

        float depositAmount = other.withdraw(300);

        result.deposit(depositAmount);
        return result;
    }
};

int main()
{
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    cout << endl;
    current.displayDetails();

    cout << endl
         << endl;

    cout << "Account Details after deposit and withdrawal:" << endl;

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    cout << endl;
    current.displayDetails();

    cout << endl
         << endl;

    cout << "Account Details after transfer:" << endl;

    // Transfer 300 from savings to current
    current = current + savings;

    savings.displayDetails();
    cout << endl;
    current.displayDetails();

    cout << endl;
    cout << "Note that the overdraft limit for Jane's account is $500, so only $500 may be withdrawn from it (not $1000, as shown in the problem description)." << endl;

    return 0;
}
