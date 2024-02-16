#include <bits/stdc++.h>

using namespace std;

// int findLeastNumOfUniqueInts(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     unordered_map<int, int> mp;
//     vector<int> freq;

//     for (int i = 0; i < n; i++)
//     {
//         mp[arr[i]]++;
//     }

//     for (const auto &ele : mp)
//     {
//         freq.push_back(ele.second);
//     }

//     sort(begin(freq), end(freq));

//     for (int i = 0; i < freq.size(); i++)
//     {
//         k = k - freq[i];

//         if (k < 0)
//             return freq.size() - i;
//     }

//     return 0;
// }

// Optimal approach -> T.C = O(n), S.C = O(n)
int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mp;

    for (const int &element : arr)
    {
        mp[element]++;
    }

    vector<int> freq(n + 1, 0);
    int uniqElement = mp.size();

    for (const auto &element : mp)
    {
        int freqCount = element.second;
        freq[freqCount]++;
    }

    for (int i = 1; i <= n; i++)
    {
        int deletedElement = min(k / i, freq[i]);
        k -= deletedElement * i;
        uniqElement -= deletedElement;

        if (k <= i)
        {
            return uniqElement;
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    int k = 3;

    cout << findLeastNumOfUniqueInts(arr, k) << endl;

    return 0;
}