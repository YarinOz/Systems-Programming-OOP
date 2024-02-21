/* Assignment C++: 1
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "Menu.h"
#include <iostream>

using namespace std;

// int main() {
// 	Stack s1;
// 	Stack s2;
// 	s1.push(5);
// 	s1.push(3);	
// 	s1 += 9;
// 	cout << s1;
// 	cout << s1 + 10;
// 	cout << 20 + s1 + 10;
// 	s2.push(3);
// 	s2.push(4);
// 	s2 +=5;
// 	cout << s1 + s2;
// 	cout << s2 + s1;	
// 	Stack s3(s2);
// 	cout << s3;
// 	cout << "\n\n s1==s2 \n" << (s1 == s2 ? "true" : "false") << endl;
// 	cout << "\n\n s2==s3 \n" << (s2 == s3 ? "true" : "false") << endl;


// 	return 0;
// }

// int main() {
// 	myQueue q1;
// 	myQueue q2;
// 	q1.enQueue(5);
// 	q1.enQueue(3);
// 	q1.enQueue(10);
// 	q2.enQueue(3);
// 	q2.enQueue(4);
// 	q2.enQueue(9);
// 	q1.print();
// 	q2.print();
// 	q1.deQueue();
// 	q2.deQueue();
// 	q1.print();
// 	q2.print();
// 	cout << q1.peek() << endl;
// 	cout << q2.peek() << endl;
// 	cout << "\n\n q1 is empty \n" << (q1.isEmpty() ? "true" : "false") << endl;
// 	return 0;
// }

int main() {
	//simply creating a menu instance, then calling mainMenu(). the rest is inside mainMenu().
	Menu a;
	a.mainMenu();
	return 0;
}