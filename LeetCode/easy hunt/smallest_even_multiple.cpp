#include <bits/stdc++.h>

using namespace std;

int smallestEvenMultiple(int n)
{
    // return n & 1 == 1 ? n * 2 : n;
    return n << (n & 1);
}

int main()
{

    int n = 6;

    cout << smallestEvenMultiple(n) << endl;

    return 0;
}