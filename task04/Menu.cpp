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

void Menu::AccountDeposit(int i, double amount)
{
    if (i < 0 || i >= size)
    {
        cout << "Error: Index out of range." << endl;
        return;
    }
    bankAccounts[i]->deposit(amount);
}

void Menu::removeAccount(int i)
{
    if (i < 0 || i >= size)
    {
        cout << "Error: Index out of range." << endl;
        return;
    }
    delete bankAccounts[i];
    bankAccounts.remove(i);
    size--;
}

void Menu::AccountWithdraw(int i, double amount)
{
    if (i < 0 || i >= size)
    {
        cout << "Error: Index out of range." << endl;
        return;
    }
    bankAccounts[i]->withdraw(amount);
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
    int index;
    double amount;
    do
    {   try
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
                    Account* account = new SavingsAccount(accountNumber, accountHolderName, initialBalance, iterestRate);
                    addAccount(account); // add the account to the array
                }
                else if (accountType == 'C' || accountType == 'c')
                {
                    cout << "Enter overdraft limit: ";
                    cin >> overdraftLimit;
                    Account* account = new CheckingAccount(accountNumber, accountHolderName, initialBalance, overdraftLimit);
                    addAccount(account); // add the account to the array
                }
                else
                {
                    throw invalid_argument("Error: Invalid account type.");
                    break;
                }
                cout << "Account added successfully." << endl;
                break;
            case 2:
                cout << "Enter account index: ";
                cin >> index;
                if (index <0 || index >= size) // check if account exists
                {
                    throw invalid_argument("Error: Index out of range.");
                    break;
                }
                cout << "Enter deposit amount: ";
                cin >> amount;
                AccountDeposit(index, amount);
                break;
            case 3:
                cout << "Enter account index: ";
                cin >> index;
                if (index <0 || index >= size)// check if account exists
                {
                    throw invalid_argument("Error: Index out of range.");
                    break;
                }
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                AccountWithdraw(index, amount);
                cout << "Withdrawn " << "$" << amount << endl;
                break;
            case 4:
                cout << "Enter account index to delete: ";
                cin >> index;
                if (index <0 || index >= size)// check if account exists
                {
                    throw invalid_argument("Error: Index out of range.");
                    break;
                }
                removeAccount(index);
                cout << "Account deleted successfully." << endl;
                break;
            case 5:
                cout << "====== Account Details ======" << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << "Array index " << i << ": " << endl;
                    cout << (*bankAccounts[i]) << endl << endl;
                }
                break;
            case 6:
                for (int i = 0; i < size; i++)
                {
                    delete bankAccounts[i];
                    bankAccounts.remove(i);
                }
                cout << "Exiting..." << endl;
                choice = 6;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
        catch(const invalid_argument& e)
        {
            cout << e.what() << endl;
        }
    } while (choice != 6);
}
