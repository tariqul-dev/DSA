#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode *insertAtEnd(ListNode *head, int val)
{
    ListNode *newNode = new ListNode(val);

    if (!head)
    {
        return newNode;
    }

    ListNode *temp = head;

    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = nullptr;
    ListNode *temp = nullptr;

    if (!list1 && !list2)
        return nullptr;
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    if (list1->val < list2->val)
    {
        head = list1;
        temp = list1;
        list1 = list1->next;
    }
    else
    {
        head = list2;
        temp = list2;
        list2 = list2->next;
    }

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    if (!list1)
        temp->next = list2;
    if (!list2)
        temp->next = list1;

    return head;
}

int main()
{
    ListNode *p = nullptr;
    p = insertAtEnd(p, 5);

    print(p);

    ListNode *q = nullptr;
    q = insertAtEnd(q, 1);
    q = insertAtEnd(q, 2);
    q = insertAtEnd(q, 4);

    print(q);

    ListNode *result = mergeTwoLists(p, q);

    print(result);

    return 0;
}