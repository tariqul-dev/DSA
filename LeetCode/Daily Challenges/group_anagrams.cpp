#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();

    vector<vector<string>> result;

    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < n; i++)
    {
        string temp = strs[i];

        sort(temp.begin(), temp.end());

        mp[temp].push_back(strs[i]);
    }

    for (auto &it : mp)
    {
        result.push_back(it.second);
    }

    return result;
}

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto it : result)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }

        cout << endl;
    }

    return 0;
}