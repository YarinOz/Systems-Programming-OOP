/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#include <string>
#include "Array.h"
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
   std::string accountNumber;
   std::string accountHolderName;
   double Balance;

public:
   Account(const std::string& number, const std::string& holder, double initialBalance);
   ~Account(){};

   // getters
   double getBalance() const { return Balance; }

   // pure virtual functions
   virtual void deposit(double amount) { Balance += amount; }
   virtual void withdraw(double amount) { Balance -= amount; }

   // operator overloading
   friend ostream& operator<<(ostream& os, const Account& other);

};

#endif // ACCOUNT_H