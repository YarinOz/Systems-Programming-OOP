#include "MyQueue.h"

myQueue::myQueue(int maxQ): maxQ(maxQ)
{
    vector<int> data;
}

bool myQueue::enQueue(int val)
{
    if (data.size() < maxQ) // If the queue is not full
    {
        data.push_back(val);
        return true;
    }
    else
    {
        return false;
    }
}

bool myQueue::deQueue()
{
    if (data.size() > 0) // If the queue is not empty
    {
        data.erase(data.begin()); // Erase the first element
        return true;
    }
    else
    {
        return false;
    }
}

bool myQueue::isEmpty()
{
    return data.empty();
}

int myQueue::peek()
{
    if (data.empty())
    {
        return -1;
    }
    return data.front();
}