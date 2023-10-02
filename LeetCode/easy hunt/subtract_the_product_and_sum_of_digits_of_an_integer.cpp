#include <bits/stdc++.h>

using namespace std;

int subtractProductAndSum(int n)
{
    int product = 1, sum = 0;

    while (n > 0)
    {
        int remain = n % 10;
        sum += remain;
        product *= remain;

        n /= 10;
    }

    return product - sum;
}

int main()
{

    int n = 234;

    cout << subtractProductAndSum(n) << endl;

    return 0;
}