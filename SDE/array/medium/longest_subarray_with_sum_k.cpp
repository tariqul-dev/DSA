#include <bits/stdc++.h>

using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    // Brute force
    // int lengthOfSubArray = 0;

    // for (int i = 0; i < a.size(); i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < a.size(); j++)
    //     {
    //         sum += a[j];

    //         if (sum == k)
    //             lengthOfSubArray = max(lengthOfSubArray, j - i + 1);
    //     }
    // }

    // return lengthOfSubArray;

    // Better solution Hashing

    // map<long long, long long> prefMap;
    // long long prefSum = 0;
    // int maxLen = 0;

    // for (int i = 0; i < a.size(); i++)
    // {
    //     prefSum += a[i];

    //     if (prefSum == k)
    //     {
    //         maxLen = max(maxLen, i + 1);
    //     }

    //     long long rem = prefSum - k;

    //     if (prefMap.find(rem) != prefMap.end())
    //     {

    //         maxLen = max(maxLen, i - (int)prefMap[rem]);
    //     }

    //     if (prefMap.find(prefSum) == prefMap.end())
    //     {
    //         prefMap[prefSum] = i;
    //     }
    // }

    // return maxLen;

    // Optimal solution
    int left = 0, right = 0, maxLen = 0;
    long long sum = a[0];
    int n = a.size();

    while (right < n)
    {

        while (left <= right && sum > k) // if sum is greater than k, subtract sum by a[left] and left++
        {
            sum -= a[left];
            left++;
        }
        if (sum == k) // if sum is equal k then calculate maxLen
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        sum += a[right];
    }

    return maxLen;
}

int main()
{

    int n = 7, k = 3;
    vector<int> a = {1, 2, 3, 1, 1, 1, 1};

    cout << longestSubarrayWithSumK(a, k) << endl;

    return 0;
}