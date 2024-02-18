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
      cout << "Stack is empty" << endl;
      return -1;
   }  // Set top to the next node and delete the current top
   int data = top->get();
   StackNode *temp = top;
   top = top->getNext();
   delete temp;
   return data;
}



// int main()
// {