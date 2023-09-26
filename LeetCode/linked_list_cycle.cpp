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

void insert(int val, ListNode *&head)
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

void createCycle(ListNode *&head)
{

    ListNode *temp = head, *temp2 = head;

    while (temp2)
    {
        if (temp2->val == 3)
            break;

        temp2 = temp2->next;
    }

    while (temp->next)
        temp = temp->next;

    temp->next = temp2;
}

void print(ListNode *head)
{
    if (head)
    {
        cout << head->val << " ";
        print(head->next);
    }
}

bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

void removeCycle(ListNode *&head)
{

    ListNode *slow = head, *fast = head;

    bool cycleStatus = hasCycle(head);

    if (cycleStatus)
    {
        cout << "Cycle Detected" << endl;

        cout << "Removing Cycle..." << endl;

        // while (fast != NULL && fast->next != NULL)
        // {
        //     slow =  slow->next;
        //     fast = fast->next->next;

        //     if (slow == fast){
        //         slow = fast;
        //         fast = head;
        //         break;
        //     }
        // }

        do
        {
            slow = slow->next;
            fast = fast->next->next;
            cout << "show: " << slow->val << " fast: " << fast->val << endl;

        } while (slow != fast);

        // reinitialize
        slow = fast;
        fast = head;

        cout << "after" << endl;

        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            cout << "show: " << slow->val << " fast: " << fast->val << endl;
        }

        slow->next = NULL;

        cout << "Cycle Removed" << endl;
    }
    else
    {
        cout << "No Cycle Detected" << endl;
    }
}

int main()
{
    ListNode *head = NULL;

    insert(1, head);
    insert(2, head);
    insert(3, head);
    insert(4, head);
    insert(5, head);

    print(head);

    cout << endl
         << "Printed" << endl;

    createCycle(head);
    cout << "cycle created" << endl;

    // print(head);

    cout << hasCycle(head) << endl;

    removeCycle(head);

    return 0;
}