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
};

void _print(Node *head)
{
    if (head)
    {
        cout << head->data << " ";
        _print(head->next);
    }
}

void print(Node *head)
{
    _print(head);
    cout << endl;
}

void insertAtFront(int data, Node *&head)
{
    Node *newNode = new Node(data);

    newNode->next = head;
    head = newNode;
}

void add(int data, Node *&head)
{
    Node *newNode = new Node(data);

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

int len(Node *head)
{
    int count = 0;

    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

void insertAtIndex(int data, int index, Node *&head)
{
    Node *newNode = new Node(data);

    if (index < 0 || index >= len(head))
    {
        cout << "Range error" << endl;
        return;
    }

    if (!head)
    {
        head = newNode;
        return;
    }

    if (!head->next)
    {
        head->next = newNode;
        return;
    }

    int count = 0;
    if (count == index)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next)
    {
        if (count == index - 1)
            break;

        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void removeAtEnd(Node *&head)
{
    if (!head)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *temp = head;

    while (temp->next->next)
        temp = temp->next;

    Node *delNode = temp->next;

    temp->next = NULL;

    delete delNode;
}

void removeAtFront(Node *&head)
{
    if (!head)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *delNode = head;

    head = head->next;

    delete delNode;
}

void removeElement(int ele, Node *&head)
{
    Node *current = head, *prev = NULL;

    while (current->next)
    {
        if (current->data == ele)
            break;
        prev = current;
        current = current->next;
    }

    if (current->data != ele)
    {
        cout << "Element not found" << endl;
        return;
    }

    if (!prev)
    {
        Node *delNode = head;
        head = head->next;

        delete delNode;

        return;
    }

    prev->next = current->next;

    delete current;
}

void findMiddle(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << slow->data << endl;
}

void createCycle(int pos, Node *&head)
{

    int count = 0;
    Node *temp = head, *startNode;

    while (temp->next)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        count++;
        temp = temp->next;
    }

    temp->next = startNode;
}

bool detectCycle(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

void deleteCycle(Node *&head)
{
    if (detectCycle(head))
    {
        cout << "Cycle detected" << endl;
        cout << "Removing..." << endl;

        Node *slow = head, *fast = head;

        do
        {

            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        slow = fast;
        fast = head;

        while (slow->next != fast->next)
        {
            cout << slow->data << " ";
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = NULL;

        cout << "Cycle removed" << endl;
    }
    else
    {
        cout << "No Cycle detected" << endl;
    }
}

void reverseListPointer(Node *&head)
{
    Node *prev = NULL, *curr = head, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

Node *reverseListRecursion(Node *&head){
    if (!head->next){
        return head;
    }

    Node *newHead = reverseListRecursion(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{

    Node *head = NULL;

    insertAtFront(1, head);
    insertAtFront(2, head);
    insertAtFront(3, head);
    insertAtFront(4, head);
    add(5, head);
    add(6, head);
    // add(7, head);

    print(head);

    createCycle(3, head);

    cout << detectCycle(head) << endl;

    deleteCycle(head);
    print(head);

    // reverseListPointer(head);
    // print(head);

    head = reverseListRecursion(head);
    print(head);

    return 0;
}