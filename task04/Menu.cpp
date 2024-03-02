/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "Menu.h"

void Menu::printMenu() const
{
    cout << "====== Main Menu ======" << endl;
    cout << "1 - Add a new account" << endl;
    cout << "2 - Deposit (index, amount)" << endl;
    cout << "3 - Withdraw (index, amount)" << endl;
    cout << "4 - Delete an account (index)" << endl;
    cout << "5 - Print details of all accounts" << endl;
    cout << "6 - Exit" << endl;
    cout << "=======================================" << endl;
}

void Menu::addAccount(Account* account)
{   
    bankAccounts.add(account);
    size++;
}

CheckingAccount& Menu::createCheckingAccount(const std::string& number, const std::string& holder, double initialBalance, double overdraft)
{
    CheckingAccount* account = new CheckingAccount(number, holder, initialBalance, overdraft);
    return *account;
}

SavingsAccount& Menu::createSavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double intrestRate)
{
    SavingsAccount* account = new SavingsAccount(number, holder, initialBalance, intrestRate);
    return *account;
}

void Menu::mainMenu()
{
    int choice;
    string accountNumber;
    string accountHolderName;
    double initialBalance;
    char accountType;
    double overdraftLimit;
    double iterestRate;
    do
    {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter account holder name: ";
            cin >> accountHolderName;
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            cout << "Enter account type (S for Savings, C for Checking): " << endl;
            cin >> accountType;

            if (accountType == 'S'|| accountType == 's')
            {
                cout << "Enter interest rate: ";
                cin >> iterestRate;
                SavingsAccount* account = &createSavingsAccount(accountNumber, accountHolderName, initialBalance, iterestRate);
                addAccount(account);
            }
            else if (accountType == 'C' || accountType == 'c')
            {
                cout << "Enter overdraft limit: ";
                cin >> overdraftLimit;
                CheckingAccount* account = &createCheckingAccount(accountNumber, accountHolderName, initialBalance, overdraftLimit);
                addAccount(account);
            }
            else
            {
                cout << "Error: Invalid account type." << endl;
            }
            cout << "Account added successfully." << endl;
            break;
        case 2:
            // printAccounts();
            break;
        case 3:
            // run();
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        case 6:
            for (int i = 0; i < size; i++)
            {
                delete bankAccounts[i];
            }
            cout << "Exiting..." << endl;
            choice = 6;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
}
