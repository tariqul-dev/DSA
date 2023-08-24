#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *&head)
{

    Node *temp = head;

    do
    {
        cout << temp->data;
        if (temp->next != head)
        {
            cout << "->";
        }

        temp = temp->next;

    } while (temp != head);

    cout << endl;
}

void insertAtEnd(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return;
    }

    tail->next = newNode;
    tail = tail->next;
    tail->next = head;
}

void insertAtFirst(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL){
        head = newNode;
        tail = head;
        return;
    }

    newNode->next = head;
    head = newNode;
    tail->next = head;
}

int main()
{

    Node *head = NULL;
    Node *tail = head;

    for (int i = 0; i < 10; i++)
    {
        insertAtFirst(head, tail, i + 1);
    }

    print(head);

    for (int i = 20; i < 25; i++)
    {
        insertAtEnd(head, tail, i + 1);
    }

    print(head);

    return 0;
}