#include <bits/stdc++.h>

using namespace std;

bool isPowerOfTwo(int n)
{
    // while (n % 2 == 0)
    //     n /= 2;

    // return n == 1;

    // Optimization O(1)
    return n > 0 && !(n & (n - 1));
}

int main()
{
    int n = 16;

    cout << isPowerOfTwo(n) << endl;

    return 0;
}