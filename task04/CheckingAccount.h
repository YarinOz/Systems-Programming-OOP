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
      CheckingAccount(const std::string& number, const std::string& holder, const double initialBalance, const double overdraft);
      ~CheckingAccount(){};
      
      void deposit(const double amount) override;
      void withdraw(const double amount) override;
};


#endif // CHECKING_ACCOUNT_H