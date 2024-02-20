/* Assignment C++: 1
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "StackNode.h"
#include "Stack.h" 

Stack::Stack(): top(nullptr) {}
void Stack::push(int data)
{
   StackNode *node = new StackNode(data, top);
   top = node;
}
int Stack::pop() // check if needed to be void
{
   if (isEmpty())
   {  // Stack is empty
      cout << "Stack empty" << endl;
      return -1;
   }  // Set top to the next node and delete the current top
   int data = top->get();
   cout << "Removing " << data << endl;
   StackNode *temp = top;
   top = top->getNext();
   delete temp;
   return data;
}
 
void Stack::print(ostream& os) const
{
   if (isEmpty())
   {
      os << "The stack is empty" << endl;
      return;
   }
   StackNode *temp = top;
   int i = 1;
   while (temp != nullptr)
   {
      os << i << ". " << temp->get() << endl;
      temp = temp->getNext();
      i++;
   }
   os << endl;
}

int Stack::size() const
{
   int count = 0;
   StackNode *temp = top;
   while (temp != nullptr)
   {
      count++;
      temp = temp->getNext();
   }
   return count;
}

// Operators

Stack Stack::operator+(const Stack& other)   // stack + stack
{
   // pushing stack1 to stack2 in reverse order to get {s1,s2}
   Stack temp = other;    // copy of stack 2
   Stack pushed = *this;  // copy of stack 1
   // creating a reverse of stack 1
   Stack reverse;
   while (!pushed.isEmpty())
   {
      reverse.push(pushed.pop());
   }
   // pushing the reverse of stack 1 to stack 2
   while (!reverse.isEmpty())
   {
      temp.push(reverse.pop());
   }
   
   return temp;
}

Stack Stack::operator+(const int num)  // stack + num
{
   Stack temp = *this;
   temp.push(num);
   return temp;
}

Stack operator+(const int num, const Stack& other) // friend function [num + stack]
{
   Stack temp = other;
   temp.push(num);
   return temp;
}

Stack& Stack::operator+=(const int num)   // stack += num
{
   push(num);
   return *this;
}

bool Stack::operator==(const Stack& other)
{
   Stack s1 = *this;
   Stack s2 = other;
   if (s1.size() != s2.size()) //checks if of same length
   {
      return false;
   }
   while (s2.top != nullptr) // checks if elements are equal and in the same order
   {
      if (s1.pop() != s2.pop())
      {
         return false;
      }
   }
   return true;
}

ostream& operator<<(ostream& os, const Stack& other)
{
   other.print(os);
   return os;
}