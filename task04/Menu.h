/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#ifndef MENU_H
#define MENU_H
#include "Array.h"
#include "Account.h"

class Menu
{
   private:
      Array<Account*> bankAccounts;
      int size;
      // int capacity;
   public:
      Menu(): size(0) {};
      ~Menu(){};

      void mainMenu();
      void printMenu() const;
      void addAccount(Account* account);
      SavingsAccount& createSavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double intrestRate);
      CheckingAccount& createCheckingAccount(const std::string& number, const std::string& holder, double initialBalance, double overdraft);

      // void printAccounts() const;
      // void run();
};

#endif // MENU_H