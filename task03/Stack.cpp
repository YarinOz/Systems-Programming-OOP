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
void Stack::print() const
{
   if (isEmpty())
   {
      cout << "The stack is empty" << endl;
      return;
   }
   StackNode *temp = top;
   int i = 1;
   while (temp != nullptr)
   {
      cout << i << ". " << temp->get() << endl;
      temp = temp->getNext();
      i++;
   }
   cout << endl;
}



// int main()
// {