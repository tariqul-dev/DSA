#include <bits/stdc++.h>

using namespace std;

int titleToNumber(string columnTitle)
{
    int result = 0;
    for (char c : columnTitle)
    {
        int ans = c - 'A' + 1;

        result = result * 26 + ans;
    }

    return result;
}

int main()
{
    string columnTitle = "ZY";

    cout << titleToNumber(columnTitle) << endl;

    return 0;
}