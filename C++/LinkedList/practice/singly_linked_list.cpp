#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void print(Node *node = NULL)
    {
        if (node == NULL)
            _print(head);
        else
            print(node);

        cout << endl;
    }

    void _print(Node *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
            _print(node->next);
        }
    }

    int len()
    {
        int count = 0;
        Node *temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void insertAtTail(int data)
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
    }

    void insertAtFront(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertAtIndex(int data, int index)
    {

        if (index >= len())
        {
            cout << "Out of range" << endl;
            return;
        }

        int count = 0;
        if (head == NULL || count == index)
        {
            insertAtFront(data);
            return;
        }

        if (index == len() - 1)
        {
            return insertAtTail(data);
        }

        Node *temp = head;

        while (temp->next)
        {
            if (count == index - 1)
                break;
            count++;
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void popLeft()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }

        Node *delNode = head;
        head = head->next;
        delete delNode;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;

        while (temp->next->next)
        {
            temp = temp->next;
        }

        Node *delNode = temp->next;
        temp->next = NULL;
        delete delNode;
    }

    Node *_reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *newHead = _reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    void reverse()
    {
        head = _reverse(head);
    }
};

int main()
{
    LinkedList list = LinkedList();

    list.insertAtTail(4);
    list.insertAtTail(6);
    list.insertAtTail(2);
    list.insertAtTail(32);
    list.insertAtFront(545);
    list.insertAtIndex(22, 4);

    list.print();

    list.reverse();

    list.print();

    // list.insertAtFront(10);

    // list.insertAtIndex(99, 3);

    // list.print();
    // list.pop();
    // list.print();

    return 0;
}