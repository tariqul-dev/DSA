#include <bits/stdc++.h>

using namespace std;

// const int N = 1e7;
// int memory[N];

// int climbStairs(int n)
// {
//     if (n <= 2)
//         return n;

//     if (memory[N])
//         return memory[N];

//     return memory[N] = climbStairs(n - 1) + climbStairs(n - 2);
// }

int climbStairs(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{

    cout << climbStairs(3) << endl;

    return 0;
}