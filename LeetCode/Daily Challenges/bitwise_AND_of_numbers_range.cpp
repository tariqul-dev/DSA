#include <bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    // int count = 0;

    // while(left != right){
    //     left >>= 1;
    //     right >>= 1;
    //     count += 1;
    // }

    // return left <<= count;

    // one line solution

    while (right > left)
    {
        right = right & (right - 1);
    }

    return left & right;
}

int main()
{

    int left = 1, right = 2147483647;

    cout << rangeBitwiseAnd(left, right) << endl;

    return 0;
}