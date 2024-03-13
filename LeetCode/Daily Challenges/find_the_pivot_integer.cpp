#include <bits/stdc++.h>

using namespace std;

int pivotInteger(int n)
{
    // int i = 1;
    // int j = n;
    // int leftSum = 1, rightSum = n;

    // while (i < j)
    // {
    //     if (leftSum < rightSum)
    //     {
    //         i++;
    //         leftSum += i;
    //     }
    //     else
    //     {
    //         j--;
    //         rightSum += j;
    //     }
    // }

    // return leftSum == rightSum ? i : -1;

    // Optimal solution -> O(1)
    int totalSum = n * (n + 1) / 2;

    int sqOfTotal = sqrt(totalSum);

    return sqOfTotal * sqOfTotal == totalSum ? sqOfTotal : -1;
}

int main()
{

    int n = 8;

    cout << pivotInteger(n) << endl;

    return 0;
}