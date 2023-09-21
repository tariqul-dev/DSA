#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> mapS;
    unordered_map<char, int> mapT;

    for (char l : s)
    {
        mapS[l]++;
    }

    for (char l : t)
    {
        mapT[l]++;
    }

    for (char l : t)
    {
        if (mapS[l] != mapT[l])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "rat", t = "car";

    // s = "anagram", t = "nagaram";
    s = "aacc", t = "ccac";

    cout
        << isAnagram(s, t) << endl;

    return 0;
}