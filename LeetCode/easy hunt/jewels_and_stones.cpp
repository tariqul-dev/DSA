#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    int count = 0;

    for (char j : jewels)
    {
        for (char s : stones)
        {
            if (j == s)
                count++;
        }
    }

    return count;
}

int main()
{
    string jewels = "aA", stones = "aAAbbbb";

    cout << numJewelsInStones(jewels, stones) << endl;

    return 0;
}