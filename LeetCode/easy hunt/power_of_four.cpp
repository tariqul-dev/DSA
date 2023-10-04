#include <bits/stdc++.h>

using namespace std;

bool isPowerOfFour(int n)
{
    // if (n == 0)
    //     return false;
    // while (n % 4 == 0)
    //     n /= 4;

    // return n == 1;

    // Optimal solution

    return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
}

int main()
{
    int n = 2;


    cout << isPowerOfFour(n) << endl;

    return 0;
}