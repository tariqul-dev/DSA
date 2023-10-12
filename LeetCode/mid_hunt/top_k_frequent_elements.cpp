#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> freq;

    vector<int> ans;

    priority_queue<pair<int, int>> pq;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (auto m : freq)
    {
        pq.push({m.second, m.first});

        if (pq.size() > freq.size() - k)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 1, 1, 2, 3, 3, 2, 3};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    print(ans);

    return 0;
}