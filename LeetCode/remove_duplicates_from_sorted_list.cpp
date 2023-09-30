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

void print(ListNode *head)
{
    if (head)
    {
        cout << head->val << " ";
        print(head->next);
    }
}

void insert(ListNode *&head, int val)
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

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *temp = head;

    while (temp && temp->next)
    {
        if (temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
        }
        else
            temp = temp->next;
    }

    return head;
}

int main()
{

    ListNode *head = NULL;

    vector<int> nums = {1, 1, 1, 2, 3,3, 3,3};

    for (int n : nums)
    {
        insert(head, n);
    }

    print(head);
    cout << endl;

    head = deleteDuplicates(head);

    print(head);

    cout << endl;
    return 0;
}