/* Assignment C++: 1
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include "StackNode.h"
#include "Stack.h" 

Stack::Stack(): top(nullptr) {}

Stack::~Stack()
{
   while (top != nullptr)
   {
      StackNode *temp = top;
      top = top->getNext();
      delete temp;
   }
}
void Stack::push(const int data)
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

Stack::Stack(const Stack& other)  // Copy constructor
{
    // Creates deep copy of the other stack
    top = nullptr;
    StackNode* current = other.top;
    Stack temp;
   // we get and push twice to avoid reverse order
   while (current != nullptr) {
        temp.push(current->get());
        current = current->getNext();
   }
   // temp is in reverse order, so we push it to this stack
   current = temp.top;
   while (current != nullptr) {
         this->push(current->get());
         current = current->getNext();
   }
}

// Operators

Stack Stack::operator+(const Stack& other) const  // stack + stack
{
   // pushing stack1 to stack2 in reverse order to get {s1,s2}
   Stack temp(other);    // deep copy of stack 2
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
// this commented block is a different implementation of switched order of stack1 and stack2/num
// Stack Stack::operator+(const int num) const // stack + num
// {
//    // pushing stack1 to num in reverse order to get {s1,num}
//    Stack temp;    // copy of num in stack
//    temp.push(num);
//    Stack pushed = *this;  // copy of stack 1
//    // creating a reverse of stack 1
//    Stack reverse;
//    while (!pushed.isEmpty())
//    {
//       reverse.push(pushed.pop());
//    }
//    // pushing the reverse of stack 1 to num
//    while (!reverse.isEmpty())
//    {
//       temp.push(reverse.pop());
//    }
//    return temp;
// }

// Stack operator+(const int num, const Stack& other) // friend function [num + stack]
// {
//    Stack temp = other;
//    temp.push(num);
//    return temp;
// }

Stack Stack::operator+(const int num) const // stack + num
{
   Stack temp = *this;
   temp.push(num);
   return temp;

}

Stack operator+(const int num, const Stack& other) // friend function [num + stack]
{
   // pushing stack1 to num in reverse order to get {s1,num}
   Stack temp;    // copy of num in stack
   temp.push(num);
   Stack pushed(other);  // deep copy (cp ctor) of stack 1
   // creating a reverse of stack 1
   Stack reverse;
   while (!pushed.isEmpty())
   {
      reverse.push(pushed.pop());
   }
   // pushing the reverse of stack 1 to num
   while (!reverse.isEmpty())
   {
      temp.push(reverse.pop());
   }
   return temp;
}

Stack& Stack::operator+=(const int num)   // stack += num
{
   push(num);
   return *this;
}

bool Stack::operator==(const Stack& other) const
{
   Stack s1 = *this;
   Stack s2(other); // deep copy (cp ctor) of stack 2
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