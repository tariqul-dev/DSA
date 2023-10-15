#include <bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t)
{
    if (s.size() == 0)
        return t[0];

    sort(s.begin(), s.end());

    sort(t.begin(), t.end());

    char result;

    int j = 0;

    cout << "s: " << s << " t: " << t << endl;

    for (int i = 0; i < t.size(); i++)
    {
        if (s[j] != t[i])
        {
            result = t[i];
        }
        else
        {
            j++;
        }
    }

    return result;
}

int main()
{
    string s = "", t = "y";

    cout << findTheDifference(s, t) << endl;

    return 0;
}