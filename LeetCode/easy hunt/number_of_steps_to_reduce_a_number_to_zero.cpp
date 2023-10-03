#include <bits/stdc++.h>

using namespace std;

int numberOfSteps(int num)
{
    int count = 0;

    while (num > 0)
    {
        if (num % 2 == 0)
            num /= 2;
        else
            num--;
        count++;
    }
    return count;
}

int main()
{

    int num = 123;

    cout << numberOfSteps(num) << endl;

    return 0;
}