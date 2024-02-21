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
      Stack();                   // Constructor
      Stack(const Stack& other); // Copy constructor
      ~Stack(){}                 // Destructor
      
      // Methods
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
      void print(ostream& os) const;
      int size() const;
      
      // Operators 
      Stack operator+(const Stack& other) const;
      Stack operator+(const int num) const;
      friend Stack operator+(const int num, const Stack& other);
      Stack& operator+=(const int num);
      bool operator==(const Stack& other) const;
      friend ostream& operator<<(ostream& os, const Stack& other);

};
#endif