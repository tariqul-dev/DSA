#include <bits/stdc++.h>

using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

void add(int val, ListNode *&head)
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

void print(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{

    // head = [ 1, 2, 3, 4, 5 ]

    ListNode *head = NULL;

    add(1, head);
    add(2, head);
    add(3, head);
    add(4, head);
    add(5, head);

    print(head);

    ListNode *mid = middleNode(head);

    print(mid);

    return 0;
}