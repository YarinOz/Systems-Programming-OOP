/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string& number, const std::string& holder, const double initialBalance, const double overdraft)
    : Account(number, holder, initialBalance), overdraftLimit(overdraft){}

void CheckingAccount::deposit(const double amount)
{
    this->Balance += amount;
    cout << (*this) << endl;
}

void CheckingAccount::withdraw(const double amount)
{
    if (this->Balance - amount < -overdraftLimit)
    {
        throw invalid_argument("Error: Withdrawal amount exceeds overdraft limit.");
    }
    this->Balance -= amount;
    cout << (*this) << endl;
}
