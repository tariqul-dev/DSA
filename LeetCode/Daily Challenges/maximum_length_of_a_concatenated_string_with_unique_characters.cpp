#include <bits/stdc++.h>

using namespace std;

bool hasDuplicate(string &s1, string &s2)
{
    int freq[26] = {0};

    for (char &ch : s1)
    {
        if (freq[ch - 'a'] > 0)
            return true;
        freq[ch - 'a']++;
    }

    for (char &ch : s2)
    {
        if (freq[ch - 'a'] > 0)
            return true;
        freq[ch - 'a']++;
    }

    

    return false;
}

int solve(int i, string res, vector<string> &arr, int &n)
{
    if (i >= n)
        return res.size();

    int take = 0, notTake = 0;

    if (hasDuplicate(res, arr[i]))
    {
        notTake = solve(i + 1, res, arr, n);
    }
    else
    {
        notTake = solve(i + 1, res, arr, n);
        take = solve(i + 1, res + arr[i], arr, n);
    }

    return max(take, notTake);
}

int maxLength(vector<string> &arr)
{
    int n = arr.size();
    int i = 0;
    string res = "";
    return solve(i, res, arr, n);
}

int main()
{
    vector<string> arr = {"aa", "bb"};
    cout << maxLength(arr) << endl;

    // string s1 = "aa", s2 = "";

    // cout << hasDuplicate(s2, s1) << endl;

    return 0;
}