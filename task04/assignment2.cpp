/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "Menu.h"
#include <iostream>
using namespace std;
#include "SavingsAccount.h" 
#include "CheckingAccount.h"
#include <thread>
#define SLEEPDUR 2 
#define RATE 0.05 

// int main() {
// 	//simply creating a menu instance, then calling mainMenu(). the rest is inside mainMenu().
// 	Menu a;
// 	a.mainMenu();
// 	return 0;
// }

// int main() {
// 	Array<int> arr;
// 	arr.add(1);
// 	arr.add(2);
// 	arr.add(3);
// 	arr.add(2);
// 	arr.add(1);
// 	cout << "Size: " << arr.getSize() << endl;	
// 	cout << arr << endl;
// 	cout << arr[2] << endl;
// 	arr.remove(2);
// 	cout << arr[2] << endl;

// 	Array<char> arr2;
// 	arr2.add('a');
// 	arr2.add('b');
// 	cout << "Size: " << arr2.getSize() << endl;	
// 	cout << arr2 << endl;
// 	cout << arr2[0] << endl;
// 	arr2.remove(0);
// 	cout << arr2[0] << endl;
// 	return 0;
// }

// int main()
// {
// 	Account myAccount("1234", "yarin", 1000);
// 	cout << myAccount << endl;
// 	myAccount.deposit(500);
// 	cout << myAccount << endl;
// 	myAccount.withdraw(2000);
// 	cout << myAccount << endl;
// 	cout << myAccount.getBalance() << endl;
	
// 	return 0;
// }

int main()
{
	CheckingAccount checkings("CA1010", "John Doe", 100, RATE); 
	SavingsAccount savings("SA2020", "Yossi Yossi", 100, RATE); 
	std::this_thread::sleep_for(std::chrono::seconds(SLEEPDUR)); 
	savings.deposit(100); 
	std::cout << '\n' << savings.getBalance() << std::endl; 
	std::cout << '\n' << checkings.getBalance() << std::endl;
	return 0;
}
