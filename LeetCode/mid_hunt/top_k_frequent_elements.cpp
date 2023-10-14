#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
void print(vector<vector<int>> ans)
{
    for (auto i : ans)
    {
        for (int x : i)
            cout << x << " ";
        cout << endl;
    }

    cout << endl;
}

void print(map<int, int> ans)
{
    for (auto i : ans)
        cout << i.first << " -> " << i.second << endl;

    cout << endl;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // map and priority queue

    // map<int, int> freq;

    // vector<int> ans;

    // priority_queue<pair<int, int>> pq;

    // for (int num : nums)
    // {
    //     freq[num]++;
    // }

    // for (auto m : freq)
    // {
    //     pq.push({m.second, m.first});

    //     if (pq.size() > freq.size() - k)
    //     {
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }
    // }

    // return ans;

    // optimized

    vector<vector<int>> freq(nums.size() + 1);
    map<int, int> freqMap;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
        freqMap[nums[i]]++;

    for (auto m : freqMap)
        freq[m.second].push_back(m.first);

    for (int i = freq.size() - 1; i >= 0 && ans.size() < k; i--)
    {
        for (auto ele : freq[i])
        {
            ans.push_back(ele);
            if (ans.size() == k)
                return ans;
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {1};
    int k = 1;

    vector<int> ans = topKFrequent(nums, k);

    print(ans);

    return 0;
}