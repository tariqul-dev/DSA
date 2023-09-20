#include <bits/stdc++.h>

using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;

    while (n > 0)
    {
        count += n & 1;

        n = n >> 1;
    }

    return count;
}

int main()
{
    // uint32_t n = 00000000000000000000000000001011;
    // uint32_t n = 00000000000000000000000010000000;
    uint32_t n = 011111111111111111111111111111101;

    cout << n << endl;
    cout << hammingWeight(n) << endl;

    return 0;
}