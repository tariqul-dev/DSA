#include <bits/stdc++.h>

using namespace std;

int balancedStringSplit(string s)
{
    // int rCount = 0, lCount = 0;
    // int subCount = 0;

    // if (s[0] == 'R')
    //     rCount++;
    // else
    //     lCount++;

    // for (int i = 1; i < s.size(); i++)
    // {
    //     if (rCount == lCount)
    //     {
    //         subCount++;
    //         rCount = 0;
    //         lCount = 0;
    //     }
    //     if (s[i] == 'R')
    //         rCount++;
    //     else
    //         lCount++;
    // }

    // if (rCount == lCount)
    //     subCount++;

    // return subCount;

    // optimal solution
    int result = 0, count = 0;

    for (const auto &c : s)
    {
        count += c == 'L' ? 1 : -1;
        if (count == 0)
            result++;
    }

    return result;
}

int main()
{

    string s = "LLLLRRRR";

    cout << balancedStringSplit(s) << endl;
    return 0;
}