#include <bits/stdc++.h>

using namespace std;

vector<int> createLps(string pattern)
{
    int size = pattern.size();

    vector<int> lps(size);
    int index = 0, i = 1;

    lps[0] = 0;

    while (i < size)
    {
        if (pattern[index] == pattern[i])
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

int kmp(string text, string pattern)
{
    vector<int> lps = createLps(pattern);

    int i = 0, j = 0;
    // i for text
    // j for pattern

    while (i < text.size())
    {
        if (text[i] == pattern[j])
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

        if (j == pattern.size())
        {
            cout << "Found at: " << i - pattern.size() << endl;
            j = lps[j - 1];
        }
    }
}

int main()
{
    string text = "sadbutsad", pattern = "sad";

    kmp(text, pattern);

    return 0;
}