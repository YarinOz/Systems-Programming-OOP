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
      myQueue(int maxQ = 100): maxQ(maxQ){}  // Constructor
      myQueue(const myQueue &other): data(other.data), maxQ(other.maxQ){} // Copy constructor
      ~myQueue(){}   // Destructor
      bool enQueue(int val);
      bool deQueue();
      bool isEmpty();
      int peek();
      void print() const;

};

#endif //__MYQUEUE_H