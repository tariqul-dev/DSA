#include <iostream>

using namespace std;

long long mod = 1e9 + 7;

long long calculateExponent(long long base, long long power)
{
    if (power <= 0)
        return 1;

    long long halfResult = calculateExponent(base, power / 2);

    long long result = ((halfResult % mod) * (halfResult % mod)) % mod;

    if (power % 2 != 0)
        result = ((result % mod) * (base % mod)) % mod;
    return result;
}

int main()
{

    cout << calculateExponent(2, 4) << endl;
    return 0;
}