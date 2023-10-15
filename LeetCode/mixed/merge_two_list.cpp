#include <bits/stdc++.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode() {}

    ListNode(int val)
    {
        this->val = val;
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

            temp = temp->next;

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

    void print()
    {
        _print(head);
        cout << endl;
    }

    ListNode *mergeListRecursive(ListNode *&l1, ListNode *&l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *temp;

        if (l1->val < l2->val)
        {
            l1->next = mergeListRecursive(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeListRecursive(l1, l2->next);
            return l2;
        }
    }

    ListNode *mergeRecursive(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *result;

        if (l1->val < l2->val)
        {
            result = l1;
            result->next = mergeRecursive(l1->next, l2);
        }
        else
        {
            result = l2;
            result->next = mergeRecursive(l1, l2->next);
        }

        return result;
    }

    ListNode *mergeIterative(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *temp = new ListNode(-1);
        ListNode *p3 = temp;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->val < p2->val)
            {
                p3->next = new ListNode(p1->val);
                p1 = p1->next;
            }
            else
            {
                p3->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            p3 = p3->next;
        }

        while (p1 != NULL)
        {
            p3->next = new ListNode(p1->val);
            p1 = p1->next;
            p3 = p3->next;
        }
        while (p2 != NULL)
        {
            p3->next = new ListNode(p2->val);
            p2 = p2->next;
            p3 = p3->next;
        }

        return temp->next;
    }
};

void print(ListNode *node)
{
    if (node)
    {
        cout << node->val << " ";
        print(node->next);
    }
}

int main()
{
    LinkedList l1 = LinkedList();

    l1.insert(1);
    l1.insert(3);
    l1.insert(4);

    l1.print();

    LinkedList l2 = LinkedList();

    l2.insert(2);
    l2.insert(4);
    l2.insert(5);
    l2.insert(6);
    l2.insert(7);

    l2.print();

    ListNode *l3 = l1.mergeIterative(l1.head, l2.head);

    print(l3);
    cout << endl;

    l1.print();
    l2.print();

    return 0;
}