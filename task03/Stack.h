/* Assignment C++: 1
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "StackNode.h"
#include <climits>
#ifndef STACK_H
#define STACK_H

class Stack
{
   private:
      StackNode *top;

   public:
      Stack();
      ~Stack()
      {
         cout << "Stack destructor" << endl;
      }
      void push(int data);
      int pop();
      bool isEmpty() const
      {
         return top == nullptr;
      }
      int peek() const
      {
         if (isEmpty())
         {
            return INT_MIN;
         }
         return top->get();
      }
   // Operators (needed to be filled)
};
#endif