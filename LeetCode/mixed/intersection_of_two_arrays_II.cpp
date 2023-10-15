#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;
    unordered_map<int, int> visited;

    for (int i = 0; i < nums2.size(); i++)
    {
        visited[nums2[i]]++;
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        if (visited[nums1[i]] > 0)
        {
            visited[nums1[i]]--;
            result.push_back(nums1[i]);
        }
    }

    return result;
}

int main()
{

    vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4};

    vector<int> result = intersect(nums1, nums2);

    for (auto n : result)
    {
        cout << n << " ";
    }

    cout << endl;

    return 0;
}