#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() {}

    ListNode(int data)
    {
        this->val = data;
        next = NULL;
    }
};

class LinkedList
{

public:
    ListNode *head;

    LinkedList()
    {
        head = NULL;
    }

    void insert(int val)
    {
        ListNode *newNode = new ListNode(val);

        if (!head)
        {
            head = newNode;
            return;
        }

        ListNode *temp = head;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void _print(ListNode *node)
    {
        if (node)
        {
            cout << node->val << " ";

            _print(node->next);
        }
    }

    void print(ListNode *node = NULL)
    {
        if (!node)
        {
            node = head;
        }

        _print(node);

        cout << endl;
    }

    ListNode *reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    void reverse()
    {
        head = reverseList(head);
    }
};

int main()
{

    LinkedList ls;

    ls.insert(4);
    ls.insert(7);
    ls.insert(2);
    ls.insert(1);

    ls.print();
    ls.reverse();
    ls.print();

    return 0;
}