#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<string>> anagram)
{
    for (auto words : anagram)
    {
        for (auto word : words)
        {
            cout << word << " ";
        }
        cout << endl;
    }
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> result;
    map<string, vector<string>> wordMap;

    for (string s : strs)
    {
        string t = s;
        sort(t.begin(), t.end());
        wordMap[t].push_back(s);
    }

    for (auto words : wordMap)
        result.push_back(words.second);

    return result;
}

int main()
{

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams(strs);

    print(result);

    return 0;
}