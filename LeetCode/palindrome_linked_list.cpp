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

    void createList(int val)
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
};

void print(ListNode *head)
{
    if (head)
    {
        cout << head->val << " ";
        print(head->next);
    }
}

ListNode *findMidNode(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *reverseList(ListNode *head)
{
    if (head->next == NULL)
        return head;

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindrome(ListNode *head)
{

    ListNode *mid = findMidNode(head);

    ListNode *rev = reverseList(mid);

    ListNode *left = head, *right = rev;

    while (left != NULL && right != NULL)
    {
        if (left->val != right->val)
            return false;
        left = left->next;
        right = right->next;
    }

    return true;
}

int main()
{
    LinkedList l1;

    l1.createList(1);
    l1.createList(2);
    l1.createList(2);
    l1.createList(1);
    print(l1.head);
    cout << endl;

    cout << isPalindrome(l1.head) << endl;

    return 0;
}