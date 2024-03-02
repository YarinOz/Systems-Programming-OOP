/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
# include <cmath>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double annualRate)
    : Account(number, holder, initialBalance), annualInterestRate(annualRate), lastTransactionTime(std::chrono::steady_clock::now()){}

void SavingsAccount::deposit(double amount)
{  
    std::chrono::steady_clock::time_point a = std::chrono::steady_clock::now(); // current time stamp
    std::chrono::duration<int> t = std::chrono::duration_cast<std::chrono::duration<int>>(a - lastTransactionTime);
    int t_seconds = t.count();
    // A_t = A_0 * (1 + r)^(t)
    double A = getBalance() * pow(1 + annualInterestRate,t_seconds) + amount;
    Account::deposit(A - getBalance());  // deposit the difference (itrest(current balance) + amount)
    lastTransactionTime = std::chrono::steady_clock::now();
}

void SavingsAccount::withdraw(double amount)
{  
    std::chrono::steady_clock::time_point a = std::chrono::steady_clock::now(); // current time stamp
    std::chrono::duration<int> t = std::chrono::duration_cast<std::chrono::duration<int>>(a - lastTransactionTime);
    int t_seconds = t.count();
    // A_t = A_0 * (1 + r)^(t)
    double A = getBalance() * pow(1 + annualInterestRate,t_seconds);
    Account::deposit(A); // deposit the interest
    Account::withdraw(amount); // withdraw the amount
    lastTransactionTime = std::chrono::steady_clock::now();
}

