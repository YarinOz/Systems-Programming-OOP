#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const std::string& number, const std::string& holder, const double initialBalance, const double annualRate)
    : Account(number, holder, initialBalance), annualInterestRate(annualRate), lastTransactionTime(std::chrono::steady_clock::now()){}

void SavingsAccount::deposit(const double amount)
{  
    this->addInterest(); // add the interest
    this->Balance += amount;  // deposit the difference (itrest(current balance) + amount)
    cout << (*this) << endl;
}

void SavingsAccount::withdraw(const double amount)
{  
    if (this->Balance - amount < 0)
    {
        throw invalid_argument("Error: Insufficient funds.");
    }
    this->addInterest(); // add the interest
    this->Balance -= amount; // withdraw the amount
    cout << (*this) << endl;
}

void SavingsAccount::addInterest()
{
    std::chrono::steady_clock::time_point a = std::chrono::steady_clock::now(); // current time stamp
    std::chrono::duration<int> t = std::chrono::duration_cast<std::chrono::duration<int>>(a - lastTransactionTime);
    int t_seconds = t.count();
    // A_t = A_0 * (1 + r)^(t)
    double A = this->Balance * pow(1 + annualInterestRate,t_seconds);
    this->Balance = A; // deposit the interest
    lastTransactionTime = std::chrono::steady_clock::now();
}

