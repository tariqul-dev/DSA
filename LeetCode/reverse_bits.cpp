#include <bits/stdc++.h>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
    {
        result <<= 1;
        result |= n & 1;
        n >>= 1;
    }

    return result;
}

int main()
{

    uint32_t n = 0000000000000000000000000001010;

    cout << reverseBits(n) << endl;

    return 0;
}