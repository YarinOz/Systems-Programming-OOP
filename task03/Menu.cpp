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
        cout << "(1) Integer Stack" << endl;
        cout << "(2) Integer Queue Menu" << endl;
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
            cout << "Goodbye!" << endl;
            choice = 3;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 3);
}

void Menu::stackMenu()
{
    Stack *stack = new Stack(); // Dynamic allocation
    int choice;
    
    do
    {
        cout << "*** Manage your integer stack ***" << endl;
        cout << "1 Push new element" << endl;
        cout << "2 Pop element" << endl;
        cout << "3 Check if empty" << endl;
        cout << "4 Print stack elements" << endl;
        cout << "5 to exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Please insert the new element: ";
            cin >> value;
            stack->push(value);
            break;
        }
        case 2:
            cout << "Removing " << stack->pop() << endl;
            break;
        case 3:
            if (stack->isEmpty())
            {
                cout << "The stack is empty" << endl;
            }
            else
            {
                cout << "The stack is not empty" << endl;
            }
            break;
        case 4:
            cout << (*stack);
            break;
        case 5:
            delete stack; // delete stack; // Dynamic allocation
            stack = nullptr; // Set stack to nullptr to avoid dangling pointer
            return;
        default:
            cout << "Invalid selection." << endl;
            break;
        }
    } while (choice != 5);
}

void Menu::queueMenu()
{
    int choice, max_size=0;
    do{
        if (max_size != 0)
        {
            cout << "The size must be positive. Please try again." << endl;
        }
        cout << "Enter the size of the queue: ";
        cin >> max_size;
    }while (max_size < 0);
    myQueue *queue = new myQueue(max_size); // Dynamic allocation

    do
    {
        cout << "*** Welcome to Queue Menu ***" << endl;
        cout << "1 Show Queue" << endl;
        cout << "2 Insert new element" << endl;
        cout << "3 Remove element" << endl;
        cout << "4 Check the first element" << endl;
        cout << "5 to exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            queue->print();
            break;
        }
        case 2:
            int value;
            cout << "insert new element: ";
            cin >> value;
            queue->enQueue(value);
            cout << "The new queue: " << endl;
            queue->print();
            break;
        case 3:
            if (queue->isEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                queue->deQueue();
                cout << "The new queue: " << endl;
                queue->print();
            }
            break;
        case 4:
            cout << queue->peek() << endl;
            break;
        case 5:
            delete queue; // Dynamic allocation
            queue = nullptr; // Set queue to nullptr to avoid dangling pointer
            return;
        default:
            cout << "Invalid selection." << endl;
            break;
        }
    } while (choice != 5);
}



