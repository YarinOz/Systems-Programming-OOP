/* Assignment C++: 1
   Author: Yarin Oziel, ID: 319149878
   Author: Itamar Meir, ID: 208536888
*/ 

#include <iostream>
using namespace std;
#ifndef STACKNODE_H
#define STACKNODE_H

class StackNode
{
   private:
      int data;
      StackNode *next;

   public:
      StackNode(int data = 0, StackNode *next = nullptr);
      ~StackNode()
      {
         cout << "StackNode destructor" << endl;
      }
      int get() const   // Return the data (cant be changed)
      {
         return data;
      }
      StackNode *getNext() const
      {
         return next;
      }
};
#endif