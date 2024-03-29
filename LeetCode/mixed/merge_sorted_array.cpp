#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> temp;
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            temp.push_back(nums1[i]);
            i++;
        }
        else
        {
            temp.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m)
    {
        temp.push_back(nums1[i]);
        i++;
    }

    while (j < n)
    {
        temp.push_back(nums2[j]);
        j++;
    }

    nums1 = temp;
}

int main()
{
    int m = 3, n = 3;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};

    merge(nums1, m, nums2, n);

    for (auto i : nums1)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}