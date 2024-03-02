/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/
#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include "Account.h" 

class CheckingAccount : public Account
{
   private:
      double overdraftLimit;
   
   public:
      CheckingAccount(const std::string& number, const std::string& holder, double initialBalance, double overdraft);
      ~CheckingAccount(){};
      void deposit(double amount) override;
      void withdraw(double amount) override;
      void print(std::ostream& os) const;
      friend std::ostream& operator<<(std::ostream& os, const CheckingAccount& other);
};


#endif // CHECKING_ACCOUNT_H