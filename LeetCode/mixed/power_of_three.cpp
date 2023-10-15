#include <bits/stdc++.h>

using namespace std;

bool isPowerOfThree(int n)
{
    if (n > 0)

        while (n % 3 == 0)
            n /= 3;

    return n == 1;
}

int main()
{
    int n = 1;
    cout << isPowerOfThree(n) << endl;

    return 0;
}