/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 
#ifndef MENU_H
#define MENU_H
#include "Array.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

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
      void removeAccount(int i);
      void AccountDeposit(int i, double amount);
      void AccountWithdraw(int i, double amount);
};

#endif // MENU_H