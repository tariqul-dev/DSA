#include <bits/stdc++.h>

using namespace std;

bool compare(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

vector<int> createLps(string pattern)
{
    int size = pattern.size();
    vector<int> lps(size);
    int index = 0;
    int i = 1;
    lps[0] = 0;

    while (i < size)
    {
        if (pattern[index] == pattern[i])
        {
            lps[i++] = ++index;
        }
        else if (index != 0)
        {
            index = lps[index - 1];
        }
        else
        {
            lps[i++] = index;
        }
    }

    return lps;
}

int kmp(string text, string pattern)
{
    vector<int> lps = createLps(pattern);
    int i = 0, j = 0;

    while (i < text.size())
    {
        if (text[i] == pattern[j])
            i++, j++;

        else
            j != 0 ? j = lps[j - 1] : i++;

        if (j == pattern.size())
            return i - pattern.size();
    }

    return -1;
}

int longestStrChain(vector<string> &words)
{
    int length = 1;
    sort(words.begin(), words.end(), compare);

    for (int i = 1; i < words.size(); i++)
    {
        int index = kmp(words[i], words[i - 1]);
        cout << "index: " << index << endl;
        if (index >= 0)
        {
            cout << words[i] << endl;
            length = words[i].size();
        }
        cout << words[i] << endl;
    }

    return length;
}

int main()
{

    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    // vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};

    cout << longestStrChain(words) << endl;

    return 0;
}