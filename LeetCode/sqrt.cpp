#include <bits/stdc++.h>

using namespace std;

int mySqrt(int x)
{

    if (x <= 1)
        return x;

    long long low = 1, high = x;
    long long ans = low;

    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;

        if (val <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{

    int n = 0;

    cout << mySqrt(n) << endl;

    return 0;
}