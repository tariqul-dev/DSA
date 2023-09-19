#include <bits/stdc++.h>

using namespace std;

// using recursion
const int N = 1e7;
int memory[N];

int climbStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }

    if (memory[n])
        return memory[n];

    return memory[n] = climbStairs(n - 1) + climbStairs(n - 2);
}

// iterative and optimize space
int climbStairs(int n)
{
    int a = 0, b = 1;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        c = a + b;

        a = b;
        b = c;
    }

    return c;
}

int main()
{

    int n = 5;

    cout << climbStairs(n) << endl;

    return 0;
}