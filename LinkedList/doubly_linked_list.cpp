#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node()
    {
        next = prev = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};

void print(Node *head)
{
    if (head == NULL)
        return;

    cout << head->data;
    if (head->next != NULL)
        cout << "->";

    print(head->next);
}

void add(Node *&head, int data)
{
    Node *newNode = new Node(data);

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
    newNode->prev = temp;
}

void add(Node *&head, Node *secondNode)
{

    if (head == NULL)
    {
        head = secondNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = secondNode;
    secondNode->prev = temp;
}

void insertBeforeValue(Node *&head, int value, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head == newNode;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            break;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Not exists" << endl;
    }

    if (temp->prev == NULL)
    {
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
        return;
    }

    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
}
void insertBeforeValue(Node *&head, int value, Node *second)
{

    if (head == NULL)
    {
        head == second;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            break;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Not exists" << endl;
        return;
    }

    if (temp->prev == NULL)
    {
        Node *temp3 = second;

        while (temp3->next != NULL)
        {
            temp3 = temp3->next;
        }

        temp->prev = temp3;
        temp3->next = temp;
        head = second;
        return;
    }

    second->prev = temp->prev;
    temp->prev->next = second;

    Node *temp2 = second;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp;
    temp->prev = temp2;
}

int main()
{

    Node *head = NULL;
    Node *second = NULL;

    for (int i = 0; i < 5; i++)
    {
        add(head, i + 1);
    }
    print(head);

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        add(second, i + 20);
    }

    print(second);

    cout << endl;

    insertBeforeValue(head, 1, second);
    print(head);

    return 0;
}