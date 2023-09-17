#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string result = strs[0];

    if (strs.size() == 1)
    {
        return strs[0];
    }
    for (int i = 0; i < strs.size(); i++)
    {
        if (i + 1 < strs.size())
        {
            string x = "";

            int len = min(strs[i].size(), strs[i + 1].size());

            for (int j = 0; j < len; j++)
            {
                if (strs[i][j] != strs[i + 1][j])
                    break;

                x += strs[i][j];
            }

            if (x.size() < result.size())
            {
                result = x;
            }
        }
    }

    return result;
}

int main()
{
    vector<string> strs = {"acc", "aaa", "aaba"};

    cout << longestCommonPrefix(strs) << endl;
}