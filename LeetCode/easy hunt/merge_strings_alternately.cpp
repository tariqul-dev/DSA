#include <bits/stdc++.h>

using namespace std;

string mergeAlternately(string word1, string word2)
{
    string temp = "";
    int i = 0, j = 0;
    while (i < word1.size() || j < word2.size())
    {
        if (i < word1.size())
            temp += word1[i++];
        if (j < word2.size())
            temp += word2[j++];
    }

    return temp;
}

int main()
{
    string word1 = "abc", word2 = "pqr";

    cout << mergeAlternately(word1, word2) << endl;

    return 0;
}