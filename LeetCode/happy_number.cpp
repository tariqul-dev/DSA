#include <bits/stdc++.h>

using namespace std;

int sumOfDigitSqure(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int remain = n % 10;
        sum += remain * remain;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;

    do
    {
        slow = sumOfDigitSqure(slow);
        fast = sumOfDigitSqure(fast);
        fast = sumOfDigitSqure(fast);

        if (fast == 1)
            return fast;
    } while (slow != fast);
    return 0;
}

int main()
{
    int n = 1111111;

    cout << isHappy(n) << endl;

    return 0;
}