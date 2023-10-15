#include <bits/stdc++.h>

using namespace std;

vector<int> createLps(string needle)
{
    int size = needle.size();
    vector<int> lps(size);
    lps[0] = 0;
    int index = 0, i = 1;

    while (i < size)
    {
        if (needle[index] == needle[i])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else if (index != 0)
        {
            index = lps[index - 1];
        }
        else
        {
            lps[i] = index;
            i++;
        }
    }

    return lps;
}

int strStr(string haystack, string needle)
{
    vector<int> lps = createLps(needle);
    int i = 0, j = 0;
    while (i < haystack.size())
    {
        if (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }

        if (j == needle.size())
        {
            return i - needle.size();
        }
    }

    return -1;
}

int main()
{
    // string haystack = "sadbutsad", needle = "sad";
    string haystack = "leetcode", needle = "leeto";

    cout << strStr(haystack, needle) << endl;

    return 0;
}