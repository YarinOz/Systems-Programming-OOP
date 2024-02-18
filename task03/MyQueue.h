#include "Stack.h"
#include <vector>
#ifndef __MYQUEUE_H
#define __MYQUEUE_H

class myQueue
{
   private:
      vector<int> data;
      int maxQ;

   public:
      myQueue(int maxQ = 100) //??
      {
      }
      ~myQueue()
      {
         cout << "MyQueue destructor" << endl;
      }
      bool enQueue(int val);
      bool deQueue();
      bool isEmpty();
      int peek();

};

#endif //__MYQUEUE_H