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
        next = nullptr;
    }
};

void push_back(ListNode *&head, int val)
{
    if (!head)
    {
        head = new ListNode(val);
        return;
    }

    ListNode *newNode = new ListNode(val);
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

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
{
    int leftIndex = 0, rightIndex = 0;
    ListNode *leftNode = NULL;
    ListNode *rightNode = list1;

    for (int i = 0; i <= b; i++)
    {

        if (i == a - 1)
        {
            leftNode = rightNode;
        }

        rightNode = rightNode->next;
    }

    ListNode *removeNode = leftNode->next;

    while (removeNode->next != rightNode)
    {
        ListNode *delNode = removeNode;

        removeNode = removeNode->next;

        delete delNode;
    }

    ListNode *temp = list2;

    while (temp->next)
        temp = temp->next;

    leftNode->next = list2;
    temp->next = rightNode;

    return list1;
}

int main()
{

    ListNode *list1 = NULL;
    ListNode *list2 = NULL;

    push_back(list1, 10);
    push_back(list1, 1);
    push_back(list1, 13);
    push_back(list1, 6);
    push_back(list1, 9);
    push_back(list1, 5);

    print(list1);

    push_back(list2, 44);
    push_back(list2, 45);
    push_back(list2, 46);
    push_back(list2, 47);
    print(list2);

    int a = 3;
    int b = 4;
    ListNode *merged = mergeInBetween(list1, a, b, list2);

    print(merged);

    return 0;
}