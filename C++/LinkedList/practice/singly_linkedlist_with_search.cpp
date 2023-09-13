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
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void _print(Node *node)
    {
        if (node)
        {
            cout << node->data << " ";
            _print(node->next);
        }
    }

    void print(Node *node = NULL)
    {
        if (!node)
        {
            node = this->head;
        }

        _print(node);

        cout << endl;
    }

    int length()
    {
        int count = 0;
        Node *temp = head;

        while (temp)
        {
            temp = temp->next;
            count++;
        }

        return count;
    }

    void append(int data)
    {
        Node *newNode = new Node(data);

        if (!head)
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

    int binarySearch(int key, int low, int high)
    {

        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        Node *current = head;

        for (int i = 0; i < mid; i++)
        {
            current = current->next;
        }

        if (current->data == key)
        {
            return mid;
        }

        if (key < current->data)
        {
            return binarySearch(key, low, mid - 1);
        }
        else
        {
            return binarySearch(key, mid + 1, high);
        }
    }
};

int main()
{

    LinkedList list = LinkedList();

    for (int i = 1; i < 10; i++)
    {
        list.append(i * 2 + 1);
    }

    list.print();

    cout << list.binarySearch(19, 0, list.length() - 1) << endl;

    return 0;
}