#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    Node() {}
};

// display circular linked list
void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data;
        if (temp->next != head)
            cout << "->";

        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// =========== insertion ==========
// insert at tail
void insertAtTail(Node *&head, int data)
{

    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

int length(Node *&head){
    int len = 0;
    Node *temp = head;
    do
    {
        temp = temp->next;
        len++;
    } while (temp != head);

    return len;
}

// ============ delete ============

void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    Node *delNode = head;
    temp->next = delNode->next;
    head = delNode->next;
    delete delNode;
}

void deleteAtTail(Node *&head){
    if (head == NULL){
        cout << "Empty Linked List" << endl;
        return;
    }
    Node *temp = head;

    while (temp->next->next != head)
    {
        temp = temp->next;
    }

    Node *delNode = temp->next;

    temp->next = head;

    delete delNode;
}

int main()
{

    Node *head = NULL;

    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 10);

    display(head);
    cout << "Length: " << length(head) << endl;

    deleteAtTail(head);

    display(head);
    cout << "Length: " << length(head) << endl;

    return 0;
}