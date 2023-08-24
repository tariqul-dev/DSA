#include <bits/stdc++.h>

using namespace std;

int sum = 0;

int digitPrint(int n)
{
    if (n <= 0)
        return 0;

    return digitPrint(n / 10) + (n % 10);;
}

int main()
{

    int n = 321;

    cout << digitPrint(n) << endl;

    return 0;
}