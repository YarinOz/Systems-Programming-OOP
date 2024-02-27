/* Assignment C++: 2
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "Menu.h"
#include <iostream>

using namespace std;

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
	
// 	return 0;
// }

int main()
{
	Account myAccount("1234", "yarin", 1000);
	cout << myAccount << endl;
	myAccount.deposit(500);
	cout << myAccount << endl;
	myAccount.withdraw(2000);
	cout << myAccount << endl;
	cout << myAccount.getBalance() << endl;
	
	return 0;
}
