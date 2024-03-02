/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(const std::string& number, const std::string& holder, double initialBalance, double overdraft)
    : Account(number, holder, initialBalance), overdraftLimit(overdraft){}

void CheckingAccount::deposit(double amount)
{
    Account::deposit(amount);
}

void CheckingAccount::withdraw(double amount)
{
    if (getBalance() - amount < -overdraftLimit)
    {
        throw std::invalid_argument("Overdraft limit exceeded");
    }
    Account::withdraw(amount);
}
