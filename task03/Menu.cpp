/* Assignment C++: 1
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "Menu.h"

void Menu::mainMenu()
{
    int choice;
    do
    {
        cout << "(1) Stack" << endl;
        cout << "(2) Queue" << endl;
        cout << "(3) Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            stackMenu();
            break;
        case 2:
            queueMenu();
            break;
        case 3:
            exit();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 3);
}