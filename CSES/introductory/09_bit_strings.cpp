#include <iostream>

using namespace std;

int main()
{
    long long MOD = 10e9 + 7;
    long long n;
    cin >> n;

    long long result = 1;

    for (long long i = 1; i <= n; i++)
    {
        result = ((result % MOD) * (2 % MOD)) % MOD;
    }

    cout << result << endl;
    return 0;
}