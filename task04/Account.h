/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <cstring>
#include <cmath>
#include "Array.h"

class Account
{
protected:
   std::string accountNumber;
   std::string accountHolderName;
   double Balance;

public:
   Account(const std::string& number, const std::string& holder, const double initialBalance);
   ~Account(){};

   // getters
   double getBalance() const { return Balance; }
   void setBalance(const double balance) { Balance = balance; }

   // pure virtual functions
   virtual void deposit(const double amount)=0;
   virtual void withdraw(const double amount)=0;

   // operator overloading
   friend ostream& operator<<(ostream& os, const Account& other);

};

#endif // ACCOUNT_H