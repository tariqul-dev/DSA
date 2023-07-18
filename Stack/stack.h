#include <bits/stdc++.h>

using namespace std;

template<typename T> class Node
{
public:
    T data;
    Node *next, *prev;
    Node(T data)
    {
        this->data = data;
        next = prev = NULL;
    }
    Node() {}
};

template <typename T> class Stack
{
private:
    Node <T> *head;
    Node <T> *top;
    int length = 0;

public:
    Stack()
    {
        head = top = NULL;
    }

    // PUSH
    void push(T value)
    {
        Node<T> *newNode = new Node(value);
        if (head == NULL)
        {
            head = top = newNode;
            length++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = top->next;
        length++;
    }

    // POP
    T pop()
    {
        T popValue;
        Node <T> *popNode = top;

        if (head == NULL)
        {
            cout << "Stack Underflow" << endl;
            return popValue;
        }

        if (head == top)
        {
            head = top = NULL;
        }

        else
        {
            top = popNode->prev;
            top->next = NULL;
        }

        popValue = popNode->data;
        delete popNode;
        length--;
        return popValue;
    }

    // IS EMPTY
    bool isEmpty()
    {
        return head == NULL;
    }

    // SIZE
    int size()
    {
        return length;
    }

    // TOP VALUE
    T topValue()
    {
        if (top == NULL)
        {
            cout << "No element added" << endl;
            return;
        }

        return top->data;
    }
};
