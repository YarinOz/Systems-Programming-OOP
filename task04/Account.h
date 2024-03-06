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
   virtual ~Account(){};

   // getters
   double getBalance() const { return Balance; }
   void setBalance(const double balance) { Balance = balance; }

   // pure virtual functions
   virtual void deposit(const double amount)=0;
   virtual void withdraw(const double amount)=0;
   virtual void print(ostream& os) {   // not const because in savings print we change the balance
      os << "Account Number: " << accountNumber << endl;
      os << "Account Holder: " << accountHolderName << endl;
      os << "New Balance: " << "$" << Balance;
   };

   // operator overloading
   friend ostream& operator<<(ostream& os, Account& other){
      other.print(os);
      return os;
   }

};

#endif // ACCOUNT_H