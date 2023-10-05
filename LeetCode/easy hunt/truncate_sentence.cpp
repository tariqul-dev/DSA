#include <bits/stdc++.h>

using namespace std;

string truncateSentence(string s, int k)
{
    // int wordCount = 0, lastIndex = 0;
    // string result = "";

    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == ' ' || i + 1 == s.size())
    //     {
    //         wordCount++;
    //         lastIndex = i;
    //     }

    //     if (wordCount == k)
    //         break;
    // }

    // if (s[lastIndex] == ' ')
    //     lastIndex--;

    // for (int i = 0; i <= lastIndex; i++)
    //     result += s[i];

    // return result;

    // Optimal solution

    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ' && --k == 0)
            return s.substr(0, i);

    return s;
}

int main()
{

    string s = "What is the solution to this problem";
    int k = 4;

    cout << truncateSentence(s, k) << endl;

    return 0;
}