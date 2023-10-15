#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    string result = "";

    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            if ((s[i] >= 'A' && s[i] <= 'Z'))
                result += s[i] + 32;

            else
                result += s[i];
        }

        if (s[i] >= '0' && s[i] <= '9')
        {
            result += s[i];
        }
    }

    if (result.size() <= 1)
        return true;

    int i = 0;
    int j = result.size() - 1;

    while (i <= j)
    {
        if (result[i] != result[j])
            return false;
        i++, j--;
    }

    return true;
}

int main()
{
    // string s = "A man, a plan, a canal: Panama";
    string s = "0P";

    cout << isPalindrome(s) << endl;

    return 0;
}