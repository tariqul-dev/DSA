#include <bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s, string t)
{
    map<char, char> mapSToT;
    map<char, char> mapTToS;
    int i = s.size() - 1;

    while (i >= 0)
    {
        if ((mapSToT[s[i]] == t[i]) || (mapTToS[t[i]] == s[i]))
        {
            cout <<  s[i]  << " -> " << mapSToT[s[i]] << " " << t[i] << endl;

            cout << "alredy" << endl;
        }

        mapSToT[s[i]] = t[i];
        mapTToS[t[i]] = s[i];

        i--;
    }

    // for (auto c1 : mapSToT)
    // {
    //     cout << c1.first << " " << c1.second << endl;
    // }
    // cout << endl
    //      << endl;

    // for (auto c1 : mapTToS)
    // {
    //     cout << c1.first << " " << c1.second << endl;
    // }
    // cout << endl;

    return true;
}

int main()
{
    string s = "paper", t = "title";

    cout << isIsomorphic(s, t) << endl;

    return 0;
}