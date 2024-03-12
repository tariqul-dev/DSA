#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    int preSum = 0;
    unordered_map<int, ListNode *> mp;

    ListNode *dumNode = new ListNode(0);

    dumNode->next = head;

    mp[0] = dumNode;

    while (head != NULL)
    {
        preSum += head->val;

        if (mp.find(preSum) != mp.end())
        {
            ListNode *start = mp[preSum];
            ListNode *temp = start;

            int pSum = preSum;

            while (temp != head)
            {
                temp = temp->next;

                pSum += temp->val;

                if (temp != head)
                {
                    mp.erase(pSum);
                }
            }

            start->next = head->next;
        }
        else
        {
            mp[preSum] = head;
        }

        head = head->next;
    }

    return dumNode->next;
}

int main()
{

    return 0;
}