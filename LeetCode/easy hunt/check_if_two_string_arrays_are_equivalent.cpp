#include <bits/stdc++.h>

using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
{
    // string s1 = "", s2 = "";
    // for (int i = 0; i < max(word1.size(), word2.size()); i++)
    // {
    //     if (i < word1.size())
    //     {
    //         s1 += word1[i];
    //     }

    //     if (i < word2.size())
    //     {
    //         s2 += word2[i];
    //     }
    // }

    // return s1 == s2;

    // Optimal t(n) s(1)

    int i = 0, j = 0; // word pointer
    int m = 0, n = 0; // char pointer

    while (i < word1.size() && j < word2.size())
    {
        if (word1[i][m++] != word2[j][n++])
            return false;

        if (m >= word1[i].size())
            i++, m = 0;

        if (n >= word2[j].size())
            j++, n = 0;
    }

    return i == word1.size() && j == word2.size();
}

int main()
{
    vector<string> word1 = {"ab", "c"}, word2 = {"a", "bc"};

    cout << arrayStringsAreEqual(word1, word2) << endl;
    return 0;
}