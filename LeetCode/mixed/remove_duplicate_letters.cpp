#include <bits/stdc++.h>

using namespace std;

string removeDuplicateLetters(string s)
{
    string result = "";
    int j = 1;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i - 1] != s[i])
        {
            s[j] = s[i];
            j++;
        }
    }

    cout << s << endl;

    for (int i = 0; i < j; i++)
    {
        result += s[i];
    }

    return result;
}

int main()
{
    string s = "cbacdcbc";

    cout << removeDuplicateLetters(s) << endl;

    return 0;
}