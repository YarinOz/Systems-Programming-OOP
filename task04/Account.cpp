#include "Account.h"

Account::Account(const std::string& number, const std::string& holder, double initialBalance)
: Balance(initialBalance), accountNumber(number), accountHolderName(holder){}
