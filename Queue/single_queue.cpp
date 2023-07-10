#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int value;
    Node *next;

    Node()
    {
        next = NULL;
    }

    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

void print(Node *head)
{

    if (head == NULL)
        return;

    cout << head->value;
    if (head->next != NULL)
    {
        cout << "->";
    }

    print(head->next);
}

void dequeue(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty queue" << endl;
        return;
    }

    Node *delNode = head;
    head = head->next;

    delete delNode;
}

void enqueue(int value, Node *&head)
{

    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main()
{
    Node *head = NULL;

    enqueue(1, head);
    enqueue(2, head);
    enqueue(3, head);
    enqueue(4, head);

    print(head);

    cout << endl;

    dequeue(head);
    dequeue(head);
    dequeue(head);
    dequeue(head);
    dequeue(head);
    print(head);

    cout << endl;

    return 0;
}