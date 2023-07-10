#include <iostream>

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
        this->next = NULL;
    }
};

int len(Node *node)
{
    int length = 0;
    while (node != NULL)
    {
        length++;
        node = node->next;
    }

    return length;
}

void print(Node *node)
{
    if (node == NULL)
        return;

    cout << node->value;
    if (node->next != NULL)
        cout << " --> ";
    else
        cout << endl;
    print(node->next);

    // while (node != NULL)
    // {
    //     cout << node->value;
    //     if (node->next != NULL)
    //         cout << " --> ";
    //     node = node->next;
    // }

    // cout << endl;
}

void insertValueAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAtFornt(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;

    head = newNode;
}

void insertAtIndex(Node *&head, int index, int value)
{
    Node *newNode = new Node(value);
    int count = 0;

    if (index < 0 || index >= len(head))
    {
        cout << "Index out of range" << endl;
        return;
    }

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    if (index == count)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (count == index)
            break;
        count++;
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void removeLast(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *deletedNode = temp->next;

    temp->next = NULL;

    delete deletedNode;
}

void removeFirst(Node *&head)
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

void removeAtIndex(Node *&head, int index)
{
    int count = 0;

    if (index == count)
    {
        removeFirst(head);
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (count == index - 1)
            break;
        count++;
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;

    delete delNode;
}

int getElementAtIndex(Node *node, int index)
{
    if (node == NULL)
    {
        cout << "Empty list" << endl;
    }

    int count = 0;

    while (node != NULL)
    {
        if (count == index)
            break;

        count++;
        node = node->next;
    }

    return node->value;
}

void reverseList(Node *&head)
{
    Node *temp = head;
    Node *prev = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{

    Node *head = NULL;

    for (int i = 0; i < 10; i++)
    {
        insertValueAtEnd(head, i + 1);
    }

    print(head);

    reverseList(head);

    print(head);

    // removeAtIndex(head, 0);
    // print(head);
    // removeAtIndex(head, 5);
    // print(head);
    // insertAtIndex(head, 0, 99);
    // print(head);

    // cout << getElementAtIndex(head, 2) << endl;

    int n = 10;

    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = n - 2; k <= j; k++)
            {
                cout << k << endl;
            }
        }
    }

    return 0;
}