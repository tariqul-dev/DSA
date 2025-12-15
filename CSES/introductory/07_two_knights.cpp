#include <iostream>

using namespace std;

long long calculateAllowedPosition(long long n)
{
    long long k = n * n;
    return (k * (k - 1)) / 2;
}

long long calculateDisallowedPosition(long long n)
{
    if (n < 3)
        return 0;
    long long b = n - 2;

    return ((b * (b + 1)) / 2) * 8;
}

int main()
{
    long long n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long result = calculateAllowedPosition(i) - calculateDisallowedPosition(i);
        cout << result << endl;
    }

    cout << endl;

    return 0;
}