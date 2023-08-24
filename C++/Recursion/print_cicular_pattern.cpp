#include <bits/stdc++.h>

using namespace std;

void print(int start, int n, int &shouldReverse, int m)
{

    if (n == start - 1)
        return;

    cout << n << ' ';

    if (n == m)
        shouldReverse = 1;

    if (shouldReverse)
        --n;
    else
        ++n;

    print(start, n, shouldReverse, m);
}

int main()
{

    int shouldReverse = 0;

    int n = 10;
    int start = n;
    int m = 20;

    print(start, n, shouldReverse, m);

    return 0;
}