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
      myQueue(int maxQ = 100): maxQ(maxQ){}
      ~myQueue(){}
      bool enQueue(int val);
      bool deQueue();
      bool isEmpty();
      int peek();
      void print() const;

};

#endif //__MYQUEUE_H