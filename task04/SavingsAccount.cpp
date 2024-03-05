/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& number, const std::string& holder, const double initialBalance, const double annualRate)
    : Account(number, holder, initialBalance), annualInterestRate(annualRate), lastTransactionTime(std::chrono::steady_clock::now()){}

void SavingsAccount::deposit(const double amount)
{  
    std::chrono::steady_clock::time_point CTS = std::chrono::steady_clock::now(); // current time stamp
    std::chrono::duration<int> t = std::chrono::duration_cast<std::chrono::duration<int>>(CTS - lastTransactionTime);
    int t_seconds = t.count(); // time difference in seconds
    // A_t = A_0 * (1 + r)^(t)
    double A = (this->Balance) * pow(1 + annualInterestRate,t_seconds);
    this->Balance = A + amount;  // deposit the difference (itrest(current balance) + amount)
    lastTransactionTime = std::chrono::steady_clock::now();
    cout << (*this) << endl;
}

void SavingsAccount::withdraw(const double amount)
{  
    std::chrono::steady_clock::time_point a = std::chrono::steady_clock::now(); // current time stamp
    std::chrono::duration<int> t = std::chrono::duration_cast<std::chrono::duration<int>>(a - lastTransactionTime);
    int t_seconds = t.count();
    // A_t = A_0 * (1 + r)^(t)
    double A = this->Balance * pow(1 + annualInterestRate,t_seconds);
    this->Balance += A; // deposit the interest
    this->Balance -= amount; // withdraw the amount
    lastTransactionTime = std::chrono::steady_clock::now();
}

