/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"
#include <chrono>
#include <cstring>
#include <thread>

class SavingsAccount : public Account
{
   private:
      double annualInterestRate;
      std::chrono::steady_clock::time_point lastTransactionTime;
   
   public:
      SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double annualRate);
      ~SavingsAccount(){};
      void deposit(double amount) override;
      void withdraw(double amount) override;
      void print(std::ostream& os) const;
      friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& other);

};


#endif // SAVINGS_ACCOUNT_H