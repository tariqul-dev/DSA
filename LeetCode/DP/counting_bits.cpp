#include <bits/stdc++.h>

using namespace std;

int countingBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n = n >> 1;
    }

    return count;
}

vector<int> countBits(int n)
{
    vector<int> bitCounts(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        bitCounts[i] = countingBits(i);
    }

    return bitCounts;
}

int main()
{

    int n = 5;

    vector<int> result = countBits(n);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}