#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
    stack<int> input;
    stack<int> output;
    int peekElement;

public:
    MyQueue()
    {
        peekElement = -1;
    }

    void push(int x)
    {
        if (input.empty())
        {
            peekElement = x;
        }

        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();
        output.pop();

        return val;
    }

    int peek()
    {
        if (output.empty())
            return peekElement;

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    MyQueue myQueue = MyQueue();
    myQueue.push(1);                 // queue is: [1]
    myQueue.push(2);                 // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl;  // return 1
    cout << myQueue.pop() << endl;   // return 1, queue is [2]
    cout << myQueue.empty() << endl; // return false

    return 0;
}