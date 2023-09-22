#include <bits/stdc++.h>

using namespace std;

bool isSubsequence(string s, string t)
{
    int i = 0, j = 0; // i for t and j for s

    while (i < t.size() && j < s.size())
    {
        if (s[j] == t[i])
            j++;
        i++;
    }

    return j == s.size();
}

int main()
{

    string s = "abc", t = "acb";

    cout << isSubsequence(s, t) << endl;

    return 0;
}