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

ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return head;

    ListNode *temp = head;

    while (temp->next)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
            continue;
        }

        temp = temp->next;
    }


    return head->val == val ? head->next: head;
}

int main()
{

    ListNode *head = NULL;

    vector<int> nums = {7, 7, 7, 7, 8};
    int val = 7;

    for (int n : nums)
    {
        insert(head, n);
    }

    print(head);
    cout << endl;

    head = removeElements(head, val);

    print(head);

    cout << endl;

    return 0;
}