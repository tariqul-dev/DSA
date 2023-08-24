#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool isPalindrome(string &s, int lowerIndex, int upperIndex)
    {
        if (lowerIndex >= upperIndex)
            return true;

        if (s[lowerIndex] != s[upperIndex])
            return false;

        return isPalindrome(s, lowerIndex + 1, upperIndex - 1);
    }

    void partioning(string &s, int index, vector<string> &path, vector<vector<string>> &result)
    {
        if (index == s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                partioning(s, i + 1, path, result);

                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;

        partioning(s, 0, path, result);

        return result;
    }
};

int main()
{

    string s = "aab";

    vector<vector<string>> result = Solution().partition(s);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}